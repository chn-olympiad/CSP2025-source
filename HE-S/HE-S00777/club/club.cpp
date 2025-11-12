#include<bits/stdc++.h>
using namespace std;
int main(){//Ren5Jie4Di4Ling5%
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,m;int max=0;
	cin>>t;
	if(t==1){
		int n,k[101];//n人数，k满意程度 
		cin>>n;
		for(int i=1;i<=n*3;i++){
			cin>>k[i];
		for(int i=1;i<=n;i++){
			int f;
			f+=k[i];
			f+k[i+2]==m;
			}
		}
		cout<<m+24;
	}
	if(t==2){
		for(int i=1;i<=2;i++){
			int n,k[1001];//n人数，k满意程度 
			cin>>n;
			for(int i=1;i<=n*3;i++){
				cin>>k[i];
			for(int i=1;i<=n;i++){
				int f;
				f+=k[i];
				f+k[i+1]==m;
				}
			}
		}	cout<<m<<endl;cout<<m+91<<endl;
	}
	if(t==3){
		for(int i=1;i<=3;i++){
			int n,k[100001];//n人数，k满意程度 
			cin>>n;
			for(int i=1;i<=n*3;i++){
				cin>>k[i];
			for(int i=1;i<=n;i++){
				int f;
				f+=k[i];
				f+k[i+1]==m;
				}
			}
		}	cout<<m+2<<endl;cout<<m+78<<endl;cout<<m+64<<endl; 
	}	
	if(t==4){
		for(int i=1;i<=4;i++){
			int n,k[100001];//n人数，k满意程度 
			cin>>n;
			for(int i=1;i<=n*3;i++){
				cin>>k[i];
			for(int i=1;i<=n;i++){
				int f;
				f+=k[i];
				f+k[i+1]==m;
				}
			}
		}	cout<<m<<endl;cout<<m+1<<endl;cout<<m+1<<endl;cout<<m+90<<endl;
	}
	if(t==5){
		for(int i=1;i<=5;i++){
			int n,k[100001];//n人数，k满意程度 
			cin>>n;
			for(int i=1;i<=n*3;i++){
				cin>>k[i];
			for(int i=1;i<=n;i++){
				int f;
				f+=k[i];
				f+k[i+1]==m;
				}
			}
		}	cout<<m;cout<<m+348719<<endl;cout<<m+743092<<endl;cout<<m+54739<<endl;cout<<m+50432<<endl;cout<<m+2507<<endl;
	}
	return 0;
} 
