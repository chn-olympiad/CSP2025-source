#include <bits/stdc++.h>
using namespace std;
int a[110]; 
bool compare(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int nums=a[0];
	int b=n*m;
	sort(a,a+b,compare);
	int ans1=0,ans2=0;
	for(int i=1;i<=m;i++){
		int flag=0;
		if(i%2==0){
			if(a[(i-1)*n]<=nums){
				ans1=i;
				for(int j=1;j<=n;j++){
					if(a[(i-1)*n-j+1]==nums){
						ans2=n-j;
						flag=1;
						break;
					}
				}
				
			}
		}
		else{
			if(a[(i-1)*n]>=nums){
				ans1=i;
				for(int j=1;j<=n;j++){
					if(a[(i-1)*n+j-1]==nums){
						ans2=j;
						flag=1;				
						break;
					}
				}
	
			}
		}
		if(flag==1) break;	
	}
	cout<<ans1<<" "<<ans2<<endl; 
	return 0;
}
