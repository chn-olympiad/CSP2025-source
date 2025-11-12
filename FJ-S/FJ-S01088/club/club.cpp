#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
long long n=100000+5,sum=0;
int a[n],b[n],c[n];
while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		sum+=max(max(a[i],b[i]),c[i]);
	}		
		 cout<<sum<<endl;
		 sum=0;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
