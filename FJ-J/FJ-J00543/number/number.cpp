#include<bits/stdc++.h>
using namespace std;int a[100],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char b;
	while(cin>>b){
		if('0'<=b&&b<='9'){
			n++;
			a[b-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	return 0;
}
