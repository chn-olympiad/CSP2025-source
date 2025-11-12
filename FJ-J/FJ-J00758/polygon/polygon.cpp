#include <bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
long long ans;
long long mins;
long long c;
long long l;
int a[100000003]={};
int b[100000003]={};
int z[100000000003]={};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int e[n+5]={};
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		mins=100000003;
		for(int j = 0;j<n;j++){
			for(int k=0;k<=j;k++){
				if(a[j]==b[k]){
					continue;
				}
			}
			if(mins>a[j]){
				mins=a[j];
			}
		}
		b[i]=mins;
	}
	for(int i = 3;i<=n;i++){
		for(int j = 1;j<n-i+1;j++){
			for(int k = j+2;k<n;k++){
				c=k-j;
				long long d=0;
				for(int r=0;r<n;r++){
					for(int l = j+1;l<k;l++){
						z[d]=b[l];
						d++;
					}e[r]=d;
					for(int l =0;l<n;l++){
					
						if(z[l]>c){
								ans++;
							}
						}
					}
				}
			}
		}
	cout<<ans;
	return 0;
}
