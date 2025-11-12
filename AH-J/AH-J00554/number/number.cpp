#include<bits/stdc++.h>
using namespace std;
string a;
map<int,int> mp;
int n[100],cmp,used,ln;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	ln=a.size();
	for(int i=0;i<=ln;i++){
		if('0'<=a[i] and a[i]<='9') mp[a[i]-'0']++;
	}
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		n[it->first]=it->second;cmp++;
		used+=it->first;
	}
	if(used==0){
		cout<<0;
		return 0;
	}
	for(int i=10;i>=0;i--){
		if(n[i]!=0)
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	
}
