#include<iostream>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int max1=0;
	while(t--){
		cin>>n;
		int a[3][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
//				max1=max(a[i][j],a[i+1][j]);
			}
		}
		int b[n];
		for(int i=0;i<n;i++){
			b[i]=a[i][0];
//			cout<<b[i];
		}
		int q;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(b[j]<b[j+1]){
					q=b[j];
					b[j]=b[j+1];
					b[j+1]=q;
				}
			}
		}
		for(int i=0;i<n;i++){
			cout<<b[i]+b[i+1];
			return 0;
		}
//			cout<<b[i];
//			max1=max(b[i],max1);
//			cout<<" "<<max1<<endl;
//			if(b[i]>b[i+1]){
//				max1=b[i];
//			}
//		cout<<b[0]+b[1];
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				if(a[i][j]>a[i][j+1]){
//					sum=a[i][j];
//				}else{
//					sum=a[i][j+1];
//				}
//			}
//		}
//		cout<<sum;
//		cout<<max1;
	}
	return 0;
}
