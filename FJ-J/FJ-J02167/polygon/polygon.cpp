#include<bits/stdc++.h>
using namespace std;
int a[1000001];

int main(){
	preoper("polygon.in","r",stdin);
	preoper("polygon.out","w",stdout);
	int n;
    int m=0,x=0,j=1,m1=0,l=1;
	cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		m=0;
		for(j=1;j<=i;j++){
			m+=a[j];
		}
		for(j=n;j>=i+1;j--){
			m+=a[j];
		if(m>a[j]*2){
			m1=m1+(j-i);
			break;
		}else{
			m-=a[j];
		}
	}
    }if(n>3){
    	if((a[1]+a[2]+a[3]+a[4])>max(a[1],max(a[2],max(a[3],a[4])))*2){
    		m1++;
		}
	}
	cout<<m1%998244353;
	return 0;
}
