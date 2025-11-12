#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,b[N][2];
string t[N][2],s1,s2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i][0]>>t[i][1],t[i][0]=" "+t[i][0],t[i][1]=" "+t[i][1];
		int l=t[i][0].size()-1;
		for(int j=1;j<=l;j++){
			if(t[i][0][j]=='b') b[i][0]=j;
			if(t[i][1][j]=='b') b[i][1]=j;
		}
	}
	while(q--){
		cin>>s1>>s2,s1=" "+s1,s2=" "+s2; 
		int l=s1.size()-1,b1,b2,ans=0;
		if(s1.size()!=s2.size()){cout<<"0\n";continue;}
		for(int i=1;i<=l;i++) if(s1[i]=='b') b1=i;
		for(int i=1;i<=l;i++) if(s2[i]=='b') b2=i;
		for(int i=1;i<=n;i++){
			if(b1-b2==b[i][0]-b[i][1]){
				if(i-b[i][0]+1>=1&&i-b[i][0]+t[i][0].size()-1<=l) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
