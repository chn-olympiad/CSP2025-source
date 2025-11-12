#include<bits/stdc++.h>
#include<cstdio>
using namespace std;


int t,n,i;
int a[1000001],b[1000001],c[1000001],d[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int j=0;j<n;j++){
	
	for( i=0;i<t;i++){
		cin>>a[i];	
	}
		for( i=0;i<t;i++){
		cin>>b[i];
		}
			for( i=0;i<t;i++){
		cin>>c[i];
		}
}
	for(int j=0;j<n-1;j++){
		for(i=0;i<t-j-1;i++){
			swap(a[i],a[i+1]);
			}
		}
			for(int j=0;j<n-1;j++){
		for(i=0;i<t-j-1;i++){
			swap(b[i],b[i+1]);
			}
		}
			for(int j=0;j<n-1;j++){
		for(i=0;i<t-j-1;i++){
			swap(c[i],c[i+1]);
			}
		}
	
for(int j=0;j<n;j++){
	d[j]=a[j]+b[j]+c[j];
	cout<<d[j]<<endl;
}
	
	fclose(stdin);fclose(stdout);
	
	return 0;
} 
