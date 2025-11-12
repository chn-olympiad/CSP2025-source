#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(i!=j && i!=k && j!=k){
					if(max(max(a[i],a[j]),a[k])*2<a[i]+a[j]+a[k]){
						cnt++;
					}
				}
			}
		}
	}
	if(n>=4){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int l=k;l<=n;l++){
						if(i!=j && i!=k && j!=k && i!=l && j!=l && k!=l){
							if(max(max(max(a[i],a[j]),a[k]),a[l])*2<a[i]+a[j]+a[k]+a[l]){
								cnt++;
							}
						}
					}
				}
			}
		}
    }
	cnt=cnt%998;
	cnt=cnt%244;
	cnt=cnt%353;
	cout<<cnt;
	return 0;
} 
