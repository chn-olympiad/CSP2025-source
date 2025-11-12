#include<bits/stdc++.h>
using namespace std;

string a;
long long sum[10];


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n = a.length();
	
	for(int i = 0;i<n;i++){
		if(a[i] >= '0' && a[i] <= '9'){
			sum[a[i]-'0']++;
		}
	}
	
	for(int i = 9;i>=0;i--){
		while(sum[i] != 0){
			sum[i]--;
			cout<<i;
		}
	}
	return 0;
} 
