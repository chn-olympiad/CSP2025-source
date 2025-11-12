#include<iostream>
using namespace std;
int main(){
	long long m,n,c[500],jc=0,d=1,zer=0;
	bool a[500],flag=1;
	char l;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l;
		if(l=='1'){
			a[i]=1;
		}
		else{
			a[i]=0;
			flag=0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			jc++;
		}
	}
	if(flag){
		if(jc+m-n>0){
			cout<<0;
			return 0;
		}
		jc=n-1;
		for(int i=1;i<=jc;i++){
			d=(d*i)%998244353;
		}
		cout<<d;
		return 0;
	}
}
