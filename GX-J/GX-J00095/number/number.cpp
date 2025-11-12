#include<bits/stdc++.h>
using namespace std;
int a[10],x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.length();
	for(long long i=0;i<=l-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x=int(s[i])-48;
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
