#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,num2,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			ans=i;
			break;
		}
	}
	num=ans%n;
	num2=ans/n;
	if(num==0){
		if(num2%2==1){
			cout<<num2<<' '<<n;
		}else{
			cout<<num2<<' '<<1;
		}
	}else{
		num2++;
		if(num2%2==1){
			cout<<num2<<' '<<num;
		}else{
			cout<<num2<<' '<<n+1-num;
		}
	}
	return 0;
}
