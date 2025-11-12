#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int maxn=10e5;
int a[maxn][3],ans[5],b,c=0,num[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	memset(ans,0,sizeof(ans));
	for(int i=0;i<t;i++){
		cin>>n;
		int dn=n/2;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
				if(a[j][1]==0){
					b++;
				}
				if(a[j][2]==0){
					c++;
				}
			}
		}
		
		if(n==2){
			num[0]=a[0][0]+a[1][1];
			num[1]=a[0][0]+a[1][2];
			num[2]=a[0][1]+a[1][0];
			num[3]=a[0][1]+a[1][2];
			num[4]=a[0][2]+a[1][0];
			num[5]=a[0][2]+a[1][1];
			for(int k=0;k<6;k++){
				if(num[k]>ans[i]){
					ans[i]=num[k];
				}
			}
		}	
		else if(b==n&&c==n){
			for(int j=0;j<dn;j++){
				for(int k=1+j;k<n;k++){
					if(a[j-1][k]<a[j][k]){
						swap(a[j-1][k],a[j][k]);
					}
				}
			}
			for(int j=0;j<dn;j++){
				ans[i]+=a[j][0];
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
