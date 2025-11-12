#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,maxn;
map<string,string>mp;
string s1,s2;
string sub(int st,int len){
	string s="";
	for(int i=st;i<=st+len-1;i++)s+=s1[i];
	return s;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		int ll=s1.size();
		maxn=max(maxn,ll);
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			for(int k=1;j+k-1<=s1.size()&&k<=maxn;k++){
				if(mp[sub(j,k)]=="")continue;
				string s3=sub(0,j)+mp[sub(j,k)]+sub(j+k,s1.size()-(j+k));
				if(s3==s2)sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}//4 2 xabcx xadex ab cd bc de aa bb xabcx xadex aaaa bbbb
//i like HONKAI_STARRAIL!my uid is 130704091
