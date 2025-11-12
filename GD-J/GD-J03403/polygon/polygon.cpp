#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,a[5001],c[5001];
bool f[5001];
void zh(int s,int k,int n,int r){
	if(k>r){
		bool t=true;
		int ans=0,x=-1;
		for(int i=1;i<k;i++){
			if(c[i-1]>c[i]&&i!=1){t=false;break;}
			ans+=a[c[i]];
			if(a[c[i]]>=x)x=a[c[i]];
		}
		if(t){
			if(ans>2*x){
				cnt%=998244353;
				cnt++;
			}
		}
		return;
	}
	for(int i=s;i<=n;i++){
		if(!f[i]){
			c[k]=i;
			f[i]=true;
			zh(s+1,k+1,n,r);
			f[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=3;i<=n;i++)zh(1,1,n,i);
	printf("%d",cnt%998244353);
	return 0;
}
