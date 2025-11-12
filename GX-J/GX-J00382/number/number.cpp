#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	long long cut=0,j=0;
	
	cin>>n;
	while(n[cut]!=' '){
		cut++;
	}
	long long arr[cut]={};
	for(int i=0;i<cut;i++){
		if(n[i]>='0' && n[i]<='9'){
			arr[j]=int(n[i]);
			j++;
		}
		
	}
	sort(arr,arr+j,cmp);
	for(int i=0;i<j;i++){
		cout<<arr[i];
	}
	
}
