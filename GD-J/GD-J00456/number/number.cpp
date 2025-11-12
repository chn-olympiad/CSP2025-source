#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int f[110]={};
	string arr;
	getline(cin,arr);
	for(int i=0;i<arr.length();i++){
		if(arr[i]>='0' && arr[i]<='9')
			f[int(arr[i]-48)]++;
	}
	for(int i=9;i>=0;i--){
		while(f[i]--)
			printf("%d",i);
	}
	return 0;
}
