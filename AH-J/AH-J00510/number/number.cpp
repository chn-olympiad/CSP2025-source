#include<bits/stdc++.h>
using namespace std;
string c;
int sum[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int x=c.size();
	for(int i=0;i<x;i++){
		for(int j=0;j<=9;j++){
			if(c[i]-'0'==j)sum[j]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			cout<<i;
		}
	}
	return 0;
}
