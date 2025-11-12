#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int arr[n];
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			arr[i]=0;
		}
		else if(s[i]=='1'){
			arr[i]=1;
		}
		else if(s[i]=='2'){
			arr[i]=2;
		}
		else if(s[i]=='3'){
			arr[i]=3;
		}
		else if(s[i]=='4'){
			arr[i]=4;
		}
		else if(s[i]=='5'){
			arr[i]=5;
		}
		else if(s[i]=='6'){
			arr[i]=6;
		}
		else if(s[i]=='7'){
			arr[i]=7;
		}
		else if(s[i]=='8'){
			arr[i]=8;
		}
		else if(s[i]=='9'){
			arr[i]=9;
		}
		else{
			arr[i]=-1;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(arr[i]!=-1){
			sum++;
		}
	}
	int brr[sum];
	int m=0;
	for(int i=0;i<n;i++){
		if(arr[i]!=-1){
			brr[m]=arr[i];
			m++;
		}
	}
	for(int i=0;i<sum;i++){
		for(int j=0;j<sum-i-1;j++){
			if(brr[j]<brr[j+1]){
				swap(brr[j],brr[j+1]);
			}
		}
	}
	for(int i=0;i<sum;i++){
		cout<<brr[i];
	}
}
