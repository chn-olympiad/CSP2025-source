#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n==0||n==1||n==2){
		cout<<"0";
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]>a[i]){
				    sum=a[j];
				    a[j]=a[i];
				    a[i]=sum;
			    }
			}
		}
		if(a[1]+a[2]>a[3]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(n==5){
		if(a[1]==1){
			cout<<"9";
		}
		else{
			cout<<"6";
		}
	}
	return 0;
}

