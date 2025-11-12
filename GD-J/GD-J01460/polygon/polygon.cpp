#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],he,ans,he1;
long long cmp(long long c,long long b){
	return c>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		he1+=a[i];
	}sort(a,a+n,cmp);
	if(n==3){
		if(he1>a[0]*2){
			ans++;
		}cout<<ans;
	}else if(n==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int p=j+1;p<n;p++){
					he=a[i]+a[j]+a[p];
					if(he>2*a[i]){
						ans++;
					}
				}
			}
		}if(he1>a[0]*2){
			ans++;
		}cout<<ans;
	}else if(n==5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int p=j+1;p<n;p++){
					he=a[i]+a[j]+a[p];
					if(he>2*a[i]){
						ans++;
					}for(int q=p+1;q<n;q++){
						he=a[i]+a[j]+a[p]+a[q];
						if(he>2*a[i]){
							ans++;
						}
					}
				}
			}
		}if(he1>a[0]*2){
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
