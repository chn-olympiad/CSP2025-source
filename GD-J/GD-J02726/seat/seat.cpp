#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int arr[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	int len=n*m;
	for(int i=0;i<len;i++){
		cin>>arr[i];
	}
	int res=arr[0];
	sort(arr,arr+len,cmp);
	int pos=0;
	for(int i=0;i<len;i++){
	//	cout<<arr[i]<<" ";
		if(arr[i]==res){
			pos=i;
		}
	}
//	cout<<'\n'<<pos<<" ";
	int h=pos%n,l=pos/n;
	if(l%2!=0){
		h=n-1-h;
	}
	cout<<l+1<<" "<<h+1<<'\n';
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92*/

