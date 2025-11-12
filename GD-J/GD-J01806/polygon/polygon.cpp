#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long n,a[N],ans=0;
bool check(int i,int j){
	long long maxx=-1,sum=0;
	for(int l=i;l<=j;l++){
		if(a[l]>maxx)maxx=a[l];
		sum+=a[l];
	}
	if(sum>maxx*2)return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)==true){
				ans++; 
			}
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//11451411451411451411451411451411451411451411451411451411451
//11111111111111111111111111111111111111111111111111111111111111111111111 
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好  
//您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好 您好您好您好  
