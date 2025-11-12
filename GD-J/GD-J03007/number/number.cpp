#include <bits/stdc++.h>
using namespace std;
string v;int s[1000005]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>v;int a=0;
	for(int x=0;x<v.size();x++){
		if(v[x]>='0'&&v[x]<='9'){
			s[a]=int(v[x]-'0');a++;
		}
	} 
	sort(s,s+a);
	for(int x=a-1;x>=0;x--){
		cout<<s[x];
	}
	return 0;
} 
