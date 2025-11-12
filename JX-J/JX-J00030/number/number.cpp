#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[100001]={};
	cin>>s;
	for(long long i=0;i<=1000000;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']+=1;
		}else if(s[i]>='a' and s[i]<='z'){
		}else{
			break;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}
