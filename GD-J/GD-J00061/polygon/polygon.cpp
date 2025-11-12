#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	unsigned long long h=0,l=0;
	int zd=-1;
	for(int i=3;i<=n;i++){
		for(int j=0;j+i<=n;j++){
			h=0;
			zd=-1;
			for(int k=j;k<j+i;k++){
				if(zd<a[k]){
					zd=a[k];
				}
				h+=a[k];
			}
			if(h>(2*zd)){
				l++;
			}
		}
	}
	cout<<l;
} 
