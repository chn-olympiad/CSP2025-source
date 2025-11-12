#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
string s[N];
string ss[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans=0;
		string c,c1;
		cin>>c>>c1;
		int len=c.size();
		for(int j=-1;j<len;j++){
			
			for(int k=j+1;k<len;k++){
				string s1="",s2="",s3="";
				for(int o=0;o<=j;o++)s1+=c[o];
				for(int o=j+1;o<=k;o++)s2+=c[o];
				for(int o=k+1;o<len;o++)s3+=c[o];
				for(int l=1;l<=n;l++){
					string s4=s1+ss[l];
					s4=s4+s3;
					if(s[l]==s2&&s4==c1){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
