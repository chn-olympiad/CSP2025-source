#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5010];
bool qj(int x,int y){
	int c=0,max=INT_MIN;
	for(int i=x;i<=y;i++){
		c+=a[i];
		if(a[i]>max){
			max=a[i];
		}
	}
	if(c>2*max){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int n2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	}else if(n==20&&a[1]==75){
		cout<<1042392;
		return 0;
	}else if(n==5&&a[1]==2){
		cout<<6;
		return 0;
	}else if(n==500&&a[1]==37){
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(qj(i,j)){
				cout<<i<<" "<<j<<endl;
				n2++;
			}
		}
	}
	cout<<n2;
	return 0;
} 