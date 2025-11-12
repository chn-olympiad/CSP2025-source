#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	//for(int i=0;i<=9;i++)cout<<a[i];
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
