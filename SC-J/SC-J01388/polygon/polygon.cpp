#include<bits/stdc++.h>
using namespace std;
int a[5050],h,n;

void func(int num,int xuan){ //第几个 选了几个 
	if(num>n){
		if(xuan>=3)h++; 
		return;
	}
	func(num+1,xuan+1);
	func(num+1,xuan);
}
void dfs(int num,int xuan,int mx,int lenh){ //第几个 选了几个 现在最大值 长度和 
	if(num>n){
		if(xuan>=3 && lenh>mx*2)h++; 
		return;
	}
	dfs(num+1,xuan,mx,lenh);//不选 
	dfs(num+1,xuan+1,max(mx,a[num]),lenh+a[num]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		func(1,0);
	}
	else{
		if(n==3){
			if(2*mx<sum)h=1;
		}
		else dfs(1,0,0,0);
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 