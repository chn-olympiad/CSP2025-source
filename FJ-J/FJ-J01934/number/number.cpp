#include<bits/stdc++.h>
#define int long long 
using namespace std;
int Q ;
string s; 
int a[10];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	for(int i=0;i<s.size();i++)a[s[i]-'0']++;
//	for(int i=0;i<=9;i++)cout<<a[i]<<" ";
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	
	return ( Q ^ Q );
}
