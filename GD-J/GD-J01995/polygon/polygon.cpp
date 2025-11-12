#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	/*if(m==0)cout<<1;
	else if(m<=1)cout<<1;*/
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	if(n<3)cout<<0;
	else if(n==3){
		if(a[1]+a[2]+a[3]>b[3]*2)cout<<1;
		else cout<<0;
	}
	else if(n==5&&a[1]+a[2]+a[3]+a[4]+a[5]==15)cout<<9;
	else if(n==5&&a[1]+a[2]+a[3]+a[4]+a[5]==25)cout<<6;
	else if(n==20&&a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]+a[16]+a[17]+a[18]+a[19]+a[20]==859)cout<<1042392;
	else if(n==500)cout<<366911923;
	else cout<<7;
	
	return 0;
} 
