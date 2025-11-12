#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=215;
int t,n,ans,ret,flag,numa[N],numb[N],numc[N];
void f(int step,int a,int b,int c){
	if(a>n/2||b>n/2||c>n/2) return ;
	if(step>n){ ret=max(ret,ans);return ;}
	ans+=numa[step];f(step+1,a+1,b,c);ans-=numa[step];
	ans+=numb[step];f(step+1,a,b+1,c);ans-=numb[step];
	ans+=numc[step];f(step+1,a,b,c+1);ans-=numc[step];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;ret=0;flag=1;
		for(int i=1;i<=n;i++){
			cin>>numa[i]>>numb[i]>>numc[i];
			if(numb[i]!=0||numc[i]!=0) flag=0;
		}
		if(flag){
			sort(numa+1,numa+1+n);
			for(int i=1;i<=n/2;i++) ret+=numa[n-i+1];
		}
		else f(1,0,0,0);
		cout<<ret<<"\n";
	}
	
}