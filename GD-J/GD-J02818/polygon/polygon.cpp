#include<bits/stdc++.h>
using namespace std;
long long p[1000004],qian[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0,cou=3;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	qian[0]=0;
	qian[1]=p[1]; 
	 for(int i=2;i<=n;i++){
	 	qian[i]=p[i]+qian[i-1];
	 }
	 for(int i=3;i<=n;i++){
	 	if((qian[i]-qian[i-cou])>p[i]*2){
	 		ans++;
		 }
		 if(i==n) ans++;
	 }
	 cout<<ans*2;
	return 0;
} 
