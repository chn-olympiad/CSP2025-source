#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[4],f[1000],ans[100],flag=0,a1=0,a2=0,a3=0,A1[100],A2[100],A3[100];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		a[4]={0}; 
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[k];
			}
			if(a[1]>=a[2]&&a[1]>=a[3]){
			f[j]=a[1];a1++;A1[a1]=f[j];}
			else if (a[2]>=a[3]){
			f[j]=a[2];a2++;A3[a3]=f[j];}
			else {f[j]=a[3];a3++;A3[a3]=f[j];}
		}
			if(a1>n/2){flag++;
			sort(A1+1,A1+1+a1);
			for(int p=1;p<=n;p++)
			{ans[flag]+=f[p];
		}
			for(int j=1;j<=n/2-1;j++){
				ans[flag]-=A1[j];
			} 
		} flag++;
	 for(int p=1;p<=n;p++)
		{ans[flag]+=f[p];
		}
	}
	for(int j=1;j<=t;j++){
		cout<<ans[j]<<endl;
	}
	return 0;
} 
