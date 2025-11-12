#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dis[11451441];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			dis[j]=s[i]-'0';
			j++;
			
			
		}
	}
	sort(dis,dis+j);
	for(int i=j-1;i>=0;i--){
		cout<<dis[i];
	}
}
