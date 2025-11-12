#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
using namespace std;
int b[10];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9' && str[i]>='0'){
			b[(int)(str[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	}
}
