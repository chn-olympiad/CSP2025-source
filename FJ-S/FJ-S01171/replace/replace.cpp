#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200005];
string s2[200005];
string str1;
string str2;
vector<int> l[200005];
bool kmp(int num){
	
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int t = 1;t<=n;t++){
		cin>>s1[t]>>s2[t];
		l[t].push_back(0);
		for(int i = 1;i<s1[t].size();i++){
			int j=l[t][i-1];
			while(j>0&&s1[t][i]!=s1[t][j]){
				j=l[t][j-1];
			}
			if(s1[t][i]==s1[t][j]){
				j++;
			}
			l[t].push_back(j);
		}
	}
	while(q--){
		int ans=0;
		cin>>str1>>str2;
		if(str1.size()!=str2.size()){
			cout<<ans<<"\n";
			continue;
		}
		for(int i = 1;i<=n;i++){
			int p = 0;
			for(int k = 0;k<str1.size();k++){
				if(s1[i][p]==str1[k]){
					p++;
					if(p==s1[i].size()){
						string temp=str1;
						int cnt=1;
						for(int p1 = 0;p1<k-s1[i].size()+1;p1++){
							if(str1[p1]!=str2[p1]){
								cnt=0;
							}
						}
						for(int p1 = 0;p1<s2[i].size();p1++){
							if(str2[k-s2[i].size()+1+p1]!=s2[i][p1]){
								cnt=0;
							}
						}
						for(int p1 = k+1;p1<str1.size();p1++){
							if(str1[p1]!=str2[p1]){
								cnt=0;
							}
						}
						//aa->cc
						//abcaab
						//abcccb
						ans+=cnt;
						p--;
						p=l[i][p];
					}
				}
				else{
					p=l[i][p];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
