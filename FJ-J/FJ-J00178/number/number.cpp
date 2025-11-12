#include<iostream>
using namespace std;
string n;
int main(){
	int a[1000005];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n.size();i++){
		if(n[i]>=48&&n[i]<=57){
			a[i]=int(n[i]);
		}
	}
	for(int j=1;j<=n.size();j++){
		for(int i=1;i<=n.size();i++){
			if(a[i]>=0&&a[i]<=9&&a[i+1]>=0&&a[i+1]<=9&&a[i]<a[i+1]){
				int b=a[i+1];
				a[i+1]=a[i];
				a[i]=b;
			}
		}
	}
	for(int i=0;i<n.size();i++){
		if(a[i]>=0&&a[i]<=9)cout<<a[i];
	}
	return 0;
}
