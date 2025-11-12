#include<bits/stdc++.h>
using namespace std;
int n,t;
int b,c,d;
long long sum;
int a[100005][4];
int o[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			sum=max(max(a[1][1]+a[1+1][2],a[1][1]+a[1+1][3]),max(max(a[1][2]+a[1+1][1],a[1][2]+a[1+1][3]),max(a[1][3],a[1+1][1]+a[1+1][2])));
			cout<<sum;
		}
		else if(n==4){
			
		}
		else if(n>=1000){
			for(int i=1;i<=n;i++){
				cin>>o[i]>>a[i][2]>>a[i][3];
			}
			sort(o+1,o+n+1);
			for(int i=n;i>n/2;i--){
				sum+=o[i];
			}
			cout<<sum;
		}
				
	}
	return 0;
}
/*		int m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>max(a[i][2],a[i][3]){
				if(b+1<m){
					b++,sum+=a[i][1];
				}
				else if(b+1==m){
					if(c==
		*/
