#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k=0;
	int a[5001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			k+=0;
		}else{
			k+=1;
		}
	}
	int o=1,t=1,c;
	for(int i=0;i<k-1;i++){
		c=o+t;
		o=t;
		t=c;
	}
	cout<<c+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}