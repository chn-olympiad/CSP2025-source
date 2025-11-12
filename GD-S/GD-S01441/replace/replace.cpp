#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
};
int n,q;
node s[200010];
int solve1(){
	string s1,s2;
	cin>>s1>>s2;
	int ans=0;
	for(int i=1;i<=n;i++){
		int m=s[i].a.size();
		for(int j=0;j<s1.size();j++){
			string t=s1.substr(j,m);
			if(t==s[i].a){
				string t=s1.substr(0,j+1)+s[i].b+s1.substr(j+m,s1.size()-j+1);
				if(t==s2)ans++;
			}
		}
	}
	return 0;
}
int solve2(){
	int ans=0;
	while(q--){
		string s1,s2;
		cin>>s1,s2;
		for(int i=1;i<=n;i++){
			int m=s[i].a.size();
			for(int j=0;j<s1.size();j++){
				string t=s1.substr(j,m);
				if(t==s[i].a){
					string t=s1.substr(0,j+1)+s[i].b+s1.substr(j+m,s1.size()-j+1);
					if(t==s2)ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].b;
	if(q==1)solve1();
	else if(n<=100&&q<=100)solve2();
	return 0;
}

