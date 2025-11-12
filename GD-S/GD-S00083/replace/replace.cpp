#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,q,len,l,r;
string s[200005][2],t1,t2;
ull base[200005],sh1[200005],sh2[200005],ph1[200005],ph2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	base[0]=1,base[1]=13331;
	for(int i=2;i<=200000;i++){
		base[i]=1ull*base[i-1]*base[1]; 
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ull h1=0,h2=0; 
		for(int j=0;j<s[i][0].length();j++){
			h1=1ull*h1*base[1]+s[i][0][j]-'a'+1;
			h2=1ull*h2*base[1]+s[i][1][j]-'a'+1;
		}
		ph1[i]=h1,ph2[i]=h2;
//		cout<<h1<<" "<<h2<<"\n";
	}
//	cout<<"----\n";
	while(q--){
		cin>>t1>>t2;
		len=t1.length();
		if(len!=t2.length()){
			cout<<"0\n";
			continue;
		}
		l=-1;
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ull plen=s[i][0].length();
			if(plen<r-l+1)continue;
			for(int j=0;j+plen-1<len;j++){
				bool f1=1,f2=1;
				for(int k=0;k<plen;k++){
					if(s[i][0][k]!=t1[j+k]){
						f1=0;
						break;
					}
				}
				for(int k=0;k<plen;k++){
					if(s[i][1][k]!=t2[j+k]){
						f2=0;
						break;
					}
				}
				if(f1&&f2){
					if(j<=l&&j+plen-1>=r){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
