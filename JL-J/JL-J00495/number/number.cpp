#include<bits/stdc++.h>
using namespace std;
string a;
long long b[10],z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size()-1;i++){
		z=a[i]-'0';
		if(z>=0&&z<=9)b[z]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
