#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100],cnt,p[11];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			p[s[i]-48]++;		
		}
	}
	for(int i=9;i>=0;i--){
		int k=p[i];
		while(k--){
			cout<<i;
		}
	}
	return 0;
} //8:44 暴力
//8：50 桶 
//8：50 接 