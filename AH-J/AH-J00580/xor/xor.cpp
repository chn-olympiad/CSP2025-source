#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k,a[N];

struct node{
	int l,r;
} cnt[N];

int awh(int x,int y){
	int s=a[x];
	for (int i=x+1;i<=y;i++){
		s^=a[i];
	}
	return s;
}

int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf ("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf ("%d",&a[i]);
	}
	int len=1;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int m=awh(i,j);
			if (m==k){
				cnt[len]={i,j};
				len++;
				break;
			}
		}
	}
	int ans=0,dr=0;
	for (int i=1;i<len;i++){
		if (dr<cnt[i].l){
			bool ion=1;
			for (int j=i+1;j<len;j++){
				if (cnt[i].l<cnt[j].l && cnt[i].r>cnt[j].r){
					ion=0,i=j-1;
					break;
				}
			}
			if (ion==0) continue;
			ans++;
			dr=cnt[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
