#include<bits/stdc++.h>
using namespace std;
int a[505];
int n,m;
string s;
int ans=0;
void dfs(string now,int lev,int day,int num){
	if(now.size()==n){
		if(num>=m)ans=(ans+1)%998244353;
		return;
	}
	for(int i=0;i<n;i++){
		if(now.find(char(i+'0'))==-1){
			if(s[day]!='0'&&a[i]>lev){
				dfs(now+char(i+'0'),lev,day+1,num+1);
			}else{
				dfs(now+char(i+'0'),lev+1,day+1,num);
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs("",0,0,0);
	cout<<ans;
	return 0;
}
