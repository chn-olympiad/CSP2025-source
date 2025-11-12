#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[2*114514][3];
bool check(string s1,string s2){
	if(s1.size()!=s2.size())return 0;
	for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i])return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	int ans[n+5]={0};
	for(int i=1;i<=n;i++)cin >> s[i][1] >> s[i][2];
	for(int a=1;a<=q;a++){
		string t1,t2;
		cin >> t1 >> t2;
		for(int i=1;i<=n;i++){
			int len=s[i][1].size();
			for(int j=0;j<t1.size()-len+1;j++){
				string tmp1="",tmp2="";
				for(int k=j;k<len;k++){
					tmp1+=t1[k];
					tmp2+=t2[k]; 
				}
				if(check(s[i][1],tmp1)&&check(s[i][2],tmp2)){
					for(int k=j;k<len;k++)t2[k]=tmp1[k-j]; 
					if(check(t1,t2))ans[a]++;
				}
			}
		}
	}
	for(int a=1;a<=q;a++)cout << ans[a] << endl;
	
}

