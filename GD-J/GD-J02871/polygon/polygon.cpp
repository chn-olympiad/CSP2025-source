#include<bits/stdc++.h>
using namespace std;
int n,m,num,t,a[5007],v[5007],s[5007];
void cmp(int x,int k,int ans,int o){
	if(x==n) return ;
	for(int i=o;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			ans+=a[i];
			x++;
			if(ans>2*max(k,a[i])&&x>=3) num++;
			num%=998244353;
			cmp(x,max(k,a[i]),ans,i+1);
			x--;
			ans-=a[i];
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cmp(0,0,0,1);
	cout<<num;
	return 0;
}
