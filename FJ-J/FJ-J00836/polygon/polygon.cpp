#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
long long n,a[10000],f=0,k=1,s[9000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
	   	s[k+1]=a[i];
	   	for(long long j=k+2;j<=2*k+1;j++){
	   	    s[j]=s[j-k-1]+a[i];
			   if(j>=k+3&&s[j]>2*a[i]){
			   	f++;
			   }	
		}
		k=2*k+1;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<"1";
		else cout<<"0";
		return 0;
	} 
    else cout<<f;
	return 0;
}
