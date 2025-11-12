#include<bits/stdc++.h>
using namespace std;
int t,n,sum,s,a1[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		for(int i=0;i<3;i++){
			a1[i]=0;
		}
		
		cin>>n;
		s=n/2;
		int a[10001][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				int x;
				cin>>x;
				a[i][j]=x;
			}
		}
		if(n!=2){
			for(int k=0;k<n;k++){
				int max_i,max_j,maxn=-1;
				for(int i=0;i<n;i++){
					for(int j=0;j<3;j++){
						if(a[i][j]>=maxn&&a1[j]<s){
							maxn=a[i][j];
							max_i=i;max_j=j;
						}
					}
				}
				a1[max_j]+=1;
				sum+=maxn;
				for(int i=0;i<3;i++){
					a[max_i][i]=0;
				}
//				cout<<endl;
//				for(int i=0;i<n;i++){
//					for(int j=0;j<3;j++){
//						cout<<a[i][j]<<' ';
//					}
//					cout<<endl;
//				}
//				cout<<endl;
//				for(int j=0;j<3;j++){
//					cout<<a1[j]<<' ';
//				}
//				cout<<endl<<endl;
//				cout<<maxn<<' ';
//				cout<<endl;
			}
		
			
		}
		if(n==2){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i!=j){
						sum=max(sum,a[1][j]+a[0][i]);
					}
					
				}
			}
		}
		cout<<sum<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

