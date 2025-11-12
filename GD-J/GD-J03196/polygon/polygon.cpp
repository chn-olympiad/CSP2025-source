#include<bits/stdc++.h>
using namespace std;
int x,arr[6999]={},ans=0;
void f(int a,int b,int c){
	if(b>a)ans++;
	for(int i=0;i<c;i++){
		f(a,b+arr[i],i);
	}return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int x;
	cin>>x;
	for(int i=0;i<x;i++)cin>>arr[i];
	sort(arr,arr+x);
	for(int i=3;i<=x;i++)f(i,0,i-1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

