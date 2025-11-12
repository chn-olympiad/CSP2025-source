#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000][5],maxn[1000],maxx[1000];
bool jb=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	int s=n/2;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				cin>>a[k][j];
				if(maxn[k]<a[k][j]){
					maxn[k]=a[k][j];
					maxx[k]++;
				}
			}
		}
		for(int k=1;k<=n;k++){
			if(maxx[k]>s)break;
			else{
				int sb=0;
				for(int kk=1;kk<=n;kk++){
					sb+=maxn[kk];
				}
				cout<<sb<<"\n";
			}
		}
		for(int k=1;k<=n;k++){
			maxx[k]=0;
		}
	}
	return 0;
} 
