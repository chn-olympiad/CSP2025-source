#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,a1[100005],a2[100005],a3[100005],ans=0;
	int x[100005];
	int b1=0,b2=0,b3=0;
	
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a1[i]>>a2[i]>>a3[i];
		for(int i=1;i<=n;i++){
			if(a2[i]==0&&a3[i]==0){
				if(b1>=n/2){
					if(b2<n/2){
						b2++;
					}else if(b2>=n/2&&b3<n/2){
						b3++;
					}
				}else if(b1<n/2){
					ans+=a1[i];
					b1++;
				}
			}
			if(a3[i]==0){
				if(a1[i]>a2[i]){
					if(b1<n/2){
						ans+=a1[i];
						b1++;
					}else if(b1>=n/2){
						ans+=a2[i];
						b2++;
					}
				}
				if(a2[i]>a1[i]){
					if(b2<n/2){
						ans+=a2[i];
						b2++;
					}else if(b2>=n/2){
						ans+=a1[i];
						b1++;
					}
				}
			}
	}
	x[j]=ans;
	ans=0;
}
for(int j=1;j<=t;j++)cout<<x[j]<<endl;
	return 0;
 } 
