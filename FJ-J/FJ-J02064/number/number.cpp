#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string arr;
	cin>>arr;
	for(long long i=0;i<arr.size();i++){
		if(arr[i]>='0'&&arr[i]<='9'){
			a[arr[i]-'0']++;
			
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}