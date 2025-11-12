#include<bits/stdc++.h>
using namespace std;
long long int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	for(int i=0;i<b.size();i++)
		if('0'<=b[i]&&b[i]<='9')
			a[b[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
