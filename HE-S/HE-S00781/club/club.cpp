#include<bits/stdc++.h>
using namespace std;
int t,n[7],res[7],x,c=1,k[3];
 int a[100010][3];
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n[p];
		x=n[c]/2;
		for(int i=1;i<=n[c];i++){
		for(int j=1;j<=3;j++){
		cin>>a[i][j];
		if(a[i][2]==0&&a[i][3]==0){
			for(int i=1;i<=x;i++)
			res[p]+=max(a[i][1],a[i+1][1]);
		}
	}
}
	for(int i=1;i<=n[c];i++){
		if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]||a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
		k[1]++;
		else{if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][3]||a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
			k[2]++;
			else{if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]||a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
			k[3]++;
		}
	}
		if(k[1]>x||k[2]>x||k[3]>x){
			k[1]=0;k[2]=0;k[3]=0;
			i=1;
			swap(a[i],a[i+1]);
		}
		else res[p]=a[i][1]+a[i][2]+a[i][3];
		}
	}

for(int p=1;p<=t;p++){
cout<<res[p]<<endl;
}
	return 0;
}
