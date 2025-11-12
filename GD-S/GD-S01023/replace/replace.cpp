#include<bits/stdc++.h>
#define p 131
#define int long long
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n' 
using namespace std;
int n,q,power[200005],h1[200005],h2[200005],sm[200005],h[200005],hs;
string s1,s2;
signed main(){
	IOS
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q; 
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.size();
		s1=" "+s1,s2=" "+s2;
		for(int j=1;j<=len;j++) h1[i]=h1[i]*p+s1[i],h2[i]=h2[i]*p+s2[i];
	}
	while(q--){
		cin>>s1>>s2;
		int len=s1.size();
		s1=" "+s1,s2=" "+s2;hs=0;
		memset(h,0,sizeof(h));
		for(int j=1;j<=len;j++) h[j]=h[j-1]*p+s1[j],hs=hs*p+s2[j];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=len;j++){
				for(int k=j;k<=len;k++){
					if(h[k]-h[j-1]*power[k-j]==h1[i]*power[k-1]){
						int sum=h[j-1]+h2[i]*power[j-1]+h[len]-h[k-1]*power[k-j];
						if(sum==hs) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//¹þÏ£Ð´±ÀÁË 
