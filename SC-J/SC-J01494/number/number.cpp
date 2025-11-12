#include<bits/stdc++.h>
using namespace std;
string sss;
char a;
long long n[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sss;
	for(int x=0;x<sss.size();x++){
		a=sss[x];
	if('0'<=a&&a<='9'){
		n[a-'0']++;
	}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
}