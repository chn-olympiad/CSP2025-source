#include<bits/stdc++.h> 
using namespace std;
long long number[15]={0};
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]>=48&&a[i]<=57){
		number[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<number[i];j++){
			cout<<i;
		}
	}
	return 0;
}

