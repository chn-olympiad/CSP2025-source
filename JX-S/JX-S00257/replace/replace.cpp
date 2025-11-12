#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010],t1[200010],t2[200010];
map<string,string> m;
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int a=s1[i].size();
		string st1="",st2="";
		for(int j=0;j<a;j++){
			if(s1[i][j]!=s2[i][j]){
				st1+=s1[i][j];
				st2+=s2[i][j];
			}
		}
		m[st1]=st2;
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		cin>>t1[i]>>t2[i];
		int a=t1[i].size();
		for(int j=0;j<a;j++){
			if(t1[j]!=t2[j]){
				swap(t1[i][j],t1[i][cnt]);
				swap(t2[i][j],t2[i][cnt]);
				cnt++;
			}
		}
		string s="";
		for(int j=0;j<cnt;j++){
			s+=t1[j];
			if(m[s]!=""){
				ans++;
				s="";
			}
		}
		cout<<ans;
	}
	return 0;
}
