#include<bits/stdc++.h>
using namespace std;
struct s{
	int l,r,f;
}b[100000];
int n,k,a[500010],he[500010],m,cnt;
bool cmp(s a,s b){
	if(a.l!=b.l){
		return a.l<b.l;
	}else 
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		he[i]=he[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k) {
					m++;
					b[m].l=i,b[m].r=i,b[m].f=0;
				}
			}else{
				int c=he[j]^he[i-1];
				if(c==k){
					m++;
					b[m].l=i,b[m].r=j,b[m].f=j-i;
				}
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(b[i].l<=b[i-1].r){
			if(b[i-1].r<=b[i].r){
			b[i].l=b[i-1].l;
			b[i].r=b[i-1].r;
		}
		}else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
