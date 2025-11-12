#include <bits/stdc++.h>
using namespace std;
int n,k;
int ant;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) ant++;
	}
	if(k==0){
		if(ant==0){
			cout<<floor(1.0*n/2);
		}else{
			n=n-ant;
			ant+=floor(1.0*n/2);
			cout<<ant;
		}
	}else if(k==1){
		n-=ant;
		cout<<n;
	}
	return 0;
}
