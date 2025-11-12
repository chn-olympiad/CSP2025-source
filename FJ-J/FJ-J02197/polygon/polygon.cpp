#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int l=j+1;l<n;l++){
				if(a[i]+a[j]+a[l]>2*a[l]){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
