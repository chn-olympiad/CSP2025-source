#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
map<pair<string,string>,int>mp;
string x,y,s,ss,qq,a[100010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
		mp[{a[i][1],a[i][2]}]++;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		for(int j=0;j<x.size();j++){
			s="";
			ss="";
			for(int k=j;k<x.size();k++){
				s+=x[k];
				ss+=y[k];
				qq=x;
				qq.replace(j,k-j+1,ss);
				if(qq==y)ans+=mp[{s,ss}];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
