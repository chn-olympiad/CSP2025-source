#include<bits/stdc++.h>
using namespace std;
long long a[100],f=0;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=10;i++)a[i]=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			f=s[i]-'0';
			a[f]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}

