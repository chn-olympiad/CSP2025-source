#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100000010],num=0,sum=0,k=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int l=max(a[i],a[j]);
				int mc=max(a[k],l);
				if((a[i]+a[j]+a[k])>=mc*2){
					num++;
				}	
	}	
	}	
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int q=k+1;q<n;q++){
				int e=max(a[i],a[j]);
				int gmc=max(a[k],e);
				int s=max(gmc,a[q]);
				if((a[i]+a[j]+a[k]+a[q])>=s*2){
					sum++;
					
				}
				}
				
		
	}	
	}	
	}
	num=num/2;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		k+=a[i];	
	}
	if(k>=a[0]*2){
		num++;
	}
	cout<<num+sum;
	return 0;
} 
