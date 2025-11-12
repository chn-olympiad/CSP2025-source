#include<bits/stdc++.h>
using namespace std;
string a;
long long arr[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			arr[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(arr[i]){
			cout<<i;
			arr[i]--;
		}
	}
	return 0;
} 
