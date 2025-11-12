#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int r[n][3];
		int a[n][3];
		for(int i=1;i<=n;i++){
			int ai[3];
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				ai[j]=a[i][j];
				if(a[i][j]>a[i][j-1]){
					r[i][3]=j;
				}
			}
			sort(ai+1,ai+1+3);
			r[i][1]=ai[3]-ai[2];
			r[i][2]=ai[3];
			
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(r[i][1]<r[j][1]||(r[i][1]==r[j][1]&&r[i][2]<r[j][2])){
					int num=0;
					num=r[i][1];
					r[i][1]=r[j][1];
					r[j][1]=num;
					num=r[i][2];
					r[i][2]=r[j][2];
					r[j][2]=num;
					num=r[i][3];
					r[i][3]=r[j][3];
					r[j][3]=num;
				}
			}
		}
		int ans=0;	
		int num=1;	
		int k[3]={0,0,0};
		while(num<=n){
			if(k[r[num][3]]<n/2){
				ans+=r[num][2];
				k[r[num][3]]++;
			}else{
				ans+=r[num][2]-r[num][1];
			}
			num++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 


