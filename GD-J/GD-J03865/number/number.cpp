#include<bits/stdc++.h>
#define int long long
using namespace std;
int number[1000005];
string s;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	cin>>s; 
	int x=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			number[x++]=s[i]-'0';
		}
	}
	//for(int i=0;i<x;i++)cout<<number[i]<<" ";
	sort(number,number+x+1,cmp);
	for(int i=0;i<x;i++)cout<<number[i];
	return 0;
}
