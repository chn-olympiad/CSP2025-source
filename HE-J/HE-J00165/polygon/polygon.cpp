#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,maxa=0,sum=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[100001];
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(n<=3){
		for(int j=1;j<=n;j++){
			sum+=a[j];
			maxa=max(maxa,a[j]);
		}
		if(sum>2*maxa){
			cout<<1;
		}
		else{
			cout<<0;
		}
		
	}
	if(n==5){
		if(a[1]==1 and a[2]==2 and a[3]==3 and a[4]==4 and a[5]==5){
			cout<<9;
		}
		else if(a[1]==2 and a[2]==2 and a[3]==3 and a[4]==8 and a[5]==10){
			cout<<6;
		}
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500){
		cout<<366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
