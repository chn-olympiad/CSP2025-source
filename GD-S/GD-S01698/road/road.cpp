#include<bits/stdc++.h>
using namespace std;
int n,t,a[100001][4],ma1[100001],b[4][100001];
int num[4];
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			int ma=-1;
			for(int k=1;k<=3;k++){
				if(a[j][k]>=ma){
					ma=k;
					ma1[j]=k;	
				}
			}
			b[ma1[j]][++num[ma1[j]]]=j;
		}
		int mi=1000000000,l;
		for(int j=1;j<=3;j++){
			if(num[j]>n/2){
				for(int k=1;k<=num[j];k++){
					if(a[b[j][k]][j]-a[b[j][k]][j+1]<=mi){
						mi=a[b[j][k]][j]-a[b[j][k]][j+1];
						l=b[j][k];
					}
				}
				num[j]--;
				b[j+1][++num[j+1]]=a[l][j+1];
			}
		}
		int ans=0;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=num[j];k++){
				ans+=a[b[j][k]][j];
			}
		}
		cout<<ans<<endl;
	}
} 
