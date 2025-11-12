#include<bits/stdc++.h>
using namespace std;
	string s;
	int a[10005],o=1,b[15];
int main(){
	freopen("poker.in","r",stdin);
	feropen("poker.out","w",stdout);

	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]>=48&&s[i]<=57){
			b[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(b[i]){
			for(int t=1;t<=b[i];t++)cout<<i;

	}
	}
	}
	}

    return 0;

}
