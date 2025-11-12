#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],b[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=s[i]-'0'+0;
			b[a[cnt]]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
} 