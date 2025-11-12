#include<bits/stdc++.h> 
using namespace std;//8.45
string k;
int mp[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(mp,0,sizeof mp);
	cin>>k;
	for(int i = 0;i<k.size();i++){
		if('0'<=k[i]&&k[i]<='9'){
			mp[k[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<mp[i];j++){
			cout<<i;
		} 
	}
	return 0;
}
