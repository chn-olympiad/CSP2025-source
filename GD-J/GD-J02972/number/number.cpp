#include<bits/stdc++.h>
using namespace std;
string s;
int js[25],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		if(x>=0 && x<=9)	js[x]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=js[i];j++)
			ans=ans*10+i;
	}
    cout<<ans;
	return 0;
}
