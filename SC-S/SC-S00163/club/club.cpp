#include<bits/stdc++.h>
using namespace std;
int T;
int a[30007][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T>0){
		T--;
		int ans=0;
		int n=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			int max1=0;
			int k=0;
			for (int j=1;j<=3;j++){
				cin>>a[i][j];  
				if (a[i][j]>max1){
					max1=a[i][j];
					k=j;
				}
			}
			a[i][4]=k;	
		}
		for (int i=1;i<=n;i++){
			int x=a[i][4];
			ans+=a[i][x]; 
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
