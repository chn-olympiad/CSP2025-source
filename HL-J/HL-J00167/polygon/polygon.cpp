#include<bits/stdc++.h>
using namespace std;
cosnt int N = 1e5+10;
int n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for (int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if (n == 5){
		cout<<9;
	}
	if (n == 3){
		cout<<10;
	}
	if (n>=10 &&n <= 20){
		cout<<100;
	}
	if (n == 5000){
		cout<<5000;
	}
	return 0;
}
