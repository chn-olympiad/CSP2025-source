#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1],s,ss=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=n;k++){
					if(i!=j&&j!=k){
					s=0;
					s+=a[i]+a[j]+a[k];
					if(s>a[i+j]*2){
						cout<<i<<' '<<i+j<<endl;
						ss++;
					}
				}
			}
		}
			
				
			
		
	}
	cout<<ss;
	return 0;
} 
