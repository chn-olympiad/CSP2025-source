#include<bits/stdc++.h>
using namespace std;
void inti(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
string s;
int k;
int num[1000001];
signed main(){
	inti();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			num[++k]=c-48;
		}
	}
	sort(num+1,num+1+k,greater<int>());
	if(!num[1]){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;++i){
		cout<<num[i];
	}
	return 0;
}
