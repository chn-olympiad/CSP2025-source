#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
int a[500005];
int s[500005];
struct num{
	int l,r;
}b[500005];
int maxn=0;
bool cmp(num x,num y){
	return x.r<y.r;
}
 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==m){
				cnt++;
				b[cnt].l=i;
				b[cnt].r=j;
			}
		}
	}
	int maxn=0;
	int R=0;
	sort(b+1,b+cnt+1,cmp);
	//cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		if(b[i].l>R){
			R=b[i].r;
			maxn++;
		}	
	}
	cout<<maxn<<endl;
	return 0;
}
