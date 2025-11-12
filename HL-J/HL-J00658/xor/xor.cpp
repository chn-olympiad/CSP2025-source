#include<iostream>
#include<cstdio>
using namespace std;
int a[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) f=0;
	}
	if(k==0&&f==1) cout<<n/2<<endl;
	else if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				cnt++;
				i++;
			}
		}
		cout<<cnt<<endl;
	}
	else if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cnt++;
				i++;
			}
		}
	}
}
