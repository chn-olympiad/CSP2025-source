#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[2000005],s1[2000005];
int swei[2000005],s1wei[2000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i]>>s1[i];
	for(int i=1;i<=n;i++){
		int wei1=0,wei2=0;
		for(int j=0;j<s[i].length();j++) if(s[i][j]=='b'){swei[i]=j;break;}
		for(int j=0;j<s1[i].length();j++) if(s1[i][j]=='b'){s1wei[i]=j;break;}
	}
	for(int i=1;i<=m;i++){
		string t,t1;
		int flag=0;
		cin>>t>>t1;
		int wei1=0,wei2=0;
		int lt=t.length(),lt1=t1.length();
		for(int j=0;j<lt;j++) if(t[j]=='b'){wei1=j;break;}
		for(int j=0;j<lt1;j++) if(t1[j]=='b'){wei2=j;break;}
		int ans=0;
		for(int j=1;j<=n;j++){
//			cout<<swei[j]<<" "<<s[j].length()-1-swei[j]<<" "<<s1wei[j]<<" "<<s1[j].length()-1-s1wei[j]<<" "<<endl;
//			cout<<wei1<<" "<<t.length()-1-wei1<<" "<<wei2<<" "<<t1.length()-1-wei2<<endl;
			if(swei[j]-s1wei[j]==wei1-wei2&&swei[j]<wei1){
				if(s1[j].length()-1-s1wei[j]<=lt1-1-wei2){
					ans++;
				}
			}
		}
		printf("%lld",ans);
		printf("\n");
	}
	return 0;
}