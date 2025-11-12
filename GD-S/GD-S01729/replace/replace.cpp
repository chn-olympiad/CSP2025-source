#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n,q,st,en,cnt;
bool c;
string s11,s22,s1,s2,ss1,x,y,z;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s11>>s22;
		mp[s11]=s22;
	}
	while(q--){
		st=-1,ss1="",cnt=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0"<<'\n';
			continue;
		}
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]&&st==-1)st=i;
			if(s1[i]!=s2[i])en=i;
		}
		for(int i=st;i<=en;i++)ss1+=s1[i];
		for(int i=st;i>=0;i--){
			x="",y=ss1;
			for(int j=st-1;j>=i;j--)y=s1[j]+y;
			for(int j=0;j<i;j++)x+=s1[j];
			for(int j=en;j<s1.size();j++){
				z="";
				for(int k=en+1;k<=j;k++)y+=s1[k];
				for(int k=j+1;k<s1.size();k++)z+=s1[k];
				if(x+mp[y]+z==s2)cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
