#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=5e6+5,M=1e9+7;
#define ll long long
ll n,q,i,j,l,fa,fb,f[N],la,lb,ans,sa1[N],sa2[N],sb1[N],sb2[N];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		l=a.size();
		for(j=0;j<l;j++)if(a[j]=='b'){fa=j;sa1[i]=j;sa2[i]=l-j;break;}
		for(j=0;j<l;j++)if(b[j]=='b'){fb=j;sb1[i]=j;sb2[i]=l-j;break;}
		f[i]=fa-fb;
	}
	while(q--){
		cin>>a>>b;
		ans=0;
		la=a.size();
		lb=b.size();
		if(la!=lb){cout<<"0\n";continue;}
		for(j=0;j<la;j++)if(a[j]=='b'){fa=j;break;}
		for(j=0;j<lb;j++)if(b[j]=='b'){fb=j;break;}
		for(i=1;i<=n;i++){
			if(f[i]==fa-fb&&fa>=sa1[i]&&la-fa>=sa2[i]&&fb>=sb1[i]&&lb-fb>=sb2[i])ans++;
		}
		cout<<ans<<"\n";
	}
}
