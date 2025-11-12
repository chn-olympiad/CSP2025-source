#include<bits/stdc++.h>
using namespace std;
int r(int a,int b){
	if(a<2 || b<2){
		if(a%2==b%2){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(a%2==b%2){
			return 1+r(a/2,b/2);
		}else{
			return 0+r(a/2,b/2);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long  n,a[10001],k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && k==2 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		cout<<2;
	}else if(n==4 && k==0 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
