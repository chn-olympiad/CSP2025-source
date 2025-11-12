#include<bits/stdc++.h>
using namespace std;
int s=0;
int ans;
int a[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int maxn=-1;
			for(int k=i;k<=n-j;k++){
				if(a[k]>maxn){
					maxn=a[k];
				}
				s+=a[k];
			}
			if(s>maxn*2){
				ans++;
			}
		}
	}
	cout<<ans; 
	return 0;
}

