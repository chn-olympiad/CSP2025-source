#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][3],minn[111111],sum=0,d[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int x=max({a[i][1],a[i][2],a[i][3]});
			for(int j=1;j<=3;j++){
				minn[j]=min(a[i][j],a[i-1][j]);
				if(x==a[i][j]) {
					if(d[j]<n/2){
						d[j]++;
						sum+=x;
					}else{
						if(minn[j]<x) sum+=x-minn[j];
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
