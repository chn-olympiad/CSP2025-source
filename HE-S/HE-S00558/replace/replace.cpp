//You are nuofu
//I ask you,how do you feel at that time?
//sad?upset?yihan?angry
//but all of the mistakes are from you
//why don't you express you love earlier?
//maybe things won't turn too badly like now
//You think you're wuzhude,but you made it
//three-year-sweet-heart is no better than two the same high-school
//Remember,everything has changes before everything are in fact
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
int n,q;
map<string,string> mp;
int Dfs(string tmp,string t,int tims){
	int cnt=0;
		if(tims>1)	return 0;
	if(tmp==t){
		return 1;
	}
	for(int len=1;len<=tmp.length();len++){
		for(int i=0;i+len-1<tmp.length();i++){
			string k;
			for(int j=i;j<=i+len-1;j++){
				k+=tmp[j];
			}
			if(mp[k].size()>0){
				k=mp[k];
				string tou;
				for(int j=0;j<i;j++){
					tou+=tmp[j];
				}
				tou+=k;
				for(int j=i+len;j<tmp.length();j++){
					tou+=tmp[j];
				}
				cnt+=Dfs(tou,t,tims+1);
			}
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
//	string t=mp["5"]
//	cout<<mp["5"].size()<<12<<endl;
	int ans=0;
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		cout<<Dfs(a,b,0)<<endl; 
	}
}
//but I still can't forget her...
