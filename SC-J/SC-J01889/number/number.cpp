#include<bits/stdc++.h>
using namespace std;
map< int,int >mp;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=int(a.size()-1);i++) if(a[i]>='0'&&a[i]<='9') mp[a[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++) printf("%d",i);
	}
	return 0;
}