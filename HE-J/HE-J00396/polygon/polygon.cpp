#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				if((a[i]+a[j])>a[z]&&(a[i]+a[z])>a[j]&&(a[j]+a[z])>a[i])b++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				for(int w=z+1;w<n;w++){
					if((a[i]+a[j]+a[w])>a[z]&&(a[i]+a[z]+a[w])>a[j]&&(a[j]+a[z]+a[w])>a[i]&&(a[j]+a[z]+a[i])>a[w])b++;
				}
				
			}
		}
	}
	cout<<b;
	return 0;
}
