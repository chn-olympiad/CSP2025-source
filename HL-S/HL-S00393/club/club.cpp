#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		int myd;
		int max_myd=-1;
		int a[100],b[100],c[100];
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];		
		}for(int k=1;k<=n;k++){
			for(int ki=1;ki<=n;ki++){
				for(int kj=1;kj<=n;kj++){
					myd=myd+a[k]+a[ki]+a[kj];
					if(myd>max_myd){
						max_myd=myd;
						myd=0;
					}
				}
			}
		}cout<<max_myd<<endl;
	}
	return 0;
	
} 
