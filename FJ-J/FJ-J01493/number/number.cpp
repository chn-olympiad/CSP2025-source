#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			a[str[i]-'0'+1]++;
		}
	}
	for(int i=10;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i-1;
		}
	}
	return 0;
} 