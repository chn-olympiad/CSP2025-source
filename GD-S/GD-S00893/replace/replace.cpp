#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q,ans,l,l1;
string s[N][3],s1,s2,s3,s4;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		ans=0;
		cin>>s1>>s2;
		l=s1.length();
		for(int i=1;i<=n;i++){
			s3=s[i][1];s4=s[i][2];
			l1=s3.length();
			for(int j=0;j+l1-1<=l;j++){
				for(int k=1;k<=l1;k++){
					if(s1[j+k-1]!=s3[k-1]) break;
					if(s2[j+k-1]!=s4[k-1]) break;
					if(k==l1){
						bool key=true;
						for(int pp=0;pp<j;pp++) if(s1[pp]!=s2[pp]){key=false;break;}
						for(int pp=j+l1;pp<l;pp++) if(s1[pp]!=s2[pp]){key=false;break;}
						if(key) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
