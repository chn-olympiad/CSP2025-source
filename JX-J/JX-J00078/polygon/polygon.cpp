#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={},ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>=3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int b=a[i],c=a[j],d=a[k];
					if((b+c)>d&&(b+d)>c&&(d+c)>b&&(b+c+d)>=(2*d)){
						ans++;
					}
				}
			}
		}
	}
	if(n>=4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						if((a[i]+a[j]+a[k]+a[l])>=(2*a[l])){
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
