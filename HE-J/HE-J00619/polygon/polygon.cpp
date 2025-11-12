#include<bits/stdc++.h>
using namespace std;
int ans=0,maxx=0,summ=0;
int a[100];
int polygon(int bianshu,int a[],int zhiqian,int n){
	if(bianshu==1){
		if(summ>maxx*2){
			return 1;
		}
	}
	else{
		for(int i=0;i<n;i++){
			summ+=a[i];
			ans+=polygon(bianshu-1,a,a[i],n);
			maxx=max(maxx,a[i]);
		}
		return ans; 
	}
}
bool b[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int lastans=0;
	int ans=0,maxx=0;
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int k=j;k<j+i;k++){
				ans+=a[k];
				maxx=max(maxx,a[k]);
			}
			if(ans>maxx*2){
				lastans++;
			}
			ans=0,maxx=0;
		}
	}
	cout<<lastans%998244353;
	return 0;
}
