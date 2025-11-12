#include<bits/stdc++.h>
using namespace std;
string s;
long long f[11],i,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9')
		f[s[i]-'0']++;
	}for(i=9;i>=0;i--){
		for(j=1;j<=f[i];j++){
			cout<<i;
		}
	}
	return 0;
}
