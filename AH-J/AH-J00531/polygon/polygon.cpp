#include<bits/stdc++.h>
using namespace std;
int a[10005],t[10005],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3])cout<<1;
		else cout<<0;
	}
	if(t[1]==n){
		int b;
		for(int i=3;i<=n;i++){
			for(int j=n;j>=i;j++){
				b*=j;
			}
		}
		cout<<b;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(a[i]+a[j]>a[k]){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int l=k;l<=n;l++){
						if(a[i]+a[j]+a[k]>a[l]){
						cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int l=k;l<=n;l++){
						for(int h=l;h<=n;h++){
							if(a[i]+a[j]+a[k]+a[l]>a[h]){
								cnt++;
							}
						}
					}
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
