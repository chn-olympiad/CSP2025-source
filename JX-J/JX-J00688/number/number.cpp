#include<bits/stdc++.h>
using namespace std;

char s;
int arr[1000005],n=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	while(cin>>s){
		if(int(s)-48>=0&&int(s)-48<=9){
			arr[n] = int(s)-48;
			n++;
		}
	}
	sort(arr,arr+n,cmp);
	if(arr[0]==0) cout<<0;
	else{
		for(int i=0;i<n;i++){
			cout<<arr[i];
		}
	}
	
	return 0;
}
