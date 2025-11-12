//GZ-S00190 贵阳市第十七中学 徐廷蔚 
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string t1,t2;
long long cnt=0;
void dfs(string t,string goal){
	if(t==goal){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		string pp=s[i][0];
		for(int j=0;j<t.size();j++){
				bool flag=1;
				for(int o=j;o<t.size();o++){
					if(t[o]!=pp[0+o-j]){
						flag=0;						
					}
				}
				string sdf=t;
			if(flag){
					for(int o=j;o<t.size();o++){
						t[o]==pp[0+o-j];
					}					

				dfs(t,goal);
				t=sdf;				
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]
		>>s[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		cnt=0;
		dfs(t1,t2);
		cout<<cnt<<"\n";
	}
	return 0;
}
