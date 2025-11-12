#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
string st;
int h[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();++i){
		if(st[i]>='0'&&st[i]<='9')h[st[i]-'0']++;
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=h[i];++j)cout<<i;
	}
	return 0;
}