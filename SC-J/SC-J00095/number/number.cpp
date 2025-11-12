#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t(char c){
	return (ll)(c-'0'); 
}
ll s[105]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	string a;
	bool flag=true;
	cin>>a;
	for(char c:a){
		if(c>='0'&&c<='9'){
			s[t(c)]++;
			if(t(c)!=0){
				flag=false;
			}
		}
	}if(flag){
		cout<<0;
		return 0;
	}for(int i=9;i>=0;i--){
		while(s[i]--){
			cout<<i;
		}
	}
	return 0;
}