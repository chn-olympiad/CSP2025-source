#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=i;j>0;j--){
			if(a[j]<a[j-1]){
				int b=a[j];
				a[j]=a[j-1];
				a[j-1]=b;
			}
		}
	}
	int b=1;
	for(int i=0;i<n;i++){
		b*=2;
		if(b/998244353>=1){
			b%=998244353;
		}
	}
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}else if(a[n-1]==1){
		cout<<b-n-n*(n-1)/2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
