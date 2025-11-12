#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0;
		int a[n+1][4];
		int count1=0,count2=0,count3=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				count1++;
				sum+=a[i][1];
			}
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
				count2++;
				sum+=a[i][2];
			}
			else{
				count3++;
				sum+=a[i][3];
			}
		}
		if(count1<=n/2&&count2<=n/2&&count3<=n/2){
			cout<<sum<<endl;
			continue;
		}
		sum=0;
		for(int i=1;i<n;i++){
			for(int k=1;k<n;k++){
				for(int j=1;j<=3;j++){
					if(a[i][j]<a[i+1][j]){
						int b=a[i+1][j];
						a[i+1][j]=a[i][j];
						a[i][j]=b;
					}
				}
			}
		}
		for(int i=1;i<=n/2;i++){
			sum+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<sum<<endl;
	}
	return 0;
}
