#include<bits/stdc++.h>
using namespace std;
int d[4],a[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int max=0,ans=0,sum=0;
	while(t--){
		ans=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>n;
			max=0;
			for(int j=1;j<=3;j++){
				cin>>d[j];
				if(ans<=n/2){
					if(d[j]>max){
						max=d[j];
					}	
				}
				sum=sum+max;
			}
			a[i]=sum;
		}
		
	}
	for(int i=1;i<=5;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}