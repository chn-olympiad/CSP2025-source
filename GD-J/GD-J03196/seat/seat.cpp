#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,k=0;
	cin>>x>>y;
	int arr[x*y]={};
	for(int i=0;i<x*y;i++)cin>>arr[i];
	int f=arr[0];
	sort(arr,arr+(x*y));
	for(;arr[k]!=f;k++);
	k=(x*y)-k;
	int a=k/x+1,b=k%x;
	bool flag=0;
	if(b==0){
		a--;
		if(a%2==1)b=x;
		else b=1;
		flag=1;
	}if(a%2==0&&flag==0)b=x-b+1;
	cout<<a<<' '<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

