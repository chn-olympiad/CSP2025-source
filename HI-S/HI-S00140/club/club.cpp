
#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	while(m--){
		int n,sum = 0;
		cin>>n;
		int aa = 0,bb = 0,cc = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				if(aa<n/2){
					aa++;
					sum+=a[i];
				}else{
					if(b[i]>c[i]){
						if(bb<n/2){
							sum+=b[i];
						}else{
							sum+=c[i];
						}
					}else{
						if(cc<n/2){
							sum+=c[i];
						}else{
							sum+=b[i];
						}
					}
				}
			}else if(b[i]>c[i]&&b[i]>a[i]){
				if(bb<n/2){
					bb++;
					sum+=b[i];
				}else{
					if(a[i]>c[i]){
						if(aa<n/2){
							sum+=a[i];
						}else{
							sum+=c[i];
						}
					}else{
						if(cc<n/2){
							sum+=c[i];
						}else{
							sum+=a[i];
						}
					}
				}
			}else if(c[i]>b[i]&&c[i]>a[i]){
				if(cc<n/2){
					cc++;
					sum+=c[i];
				}else{
					if(a[i]>b[i]){
						if(aa<n/2){
							sum+=a[i];
						}else{
							sum+=b[i];
						}
					}else{
						if(bb<n/2){
							sum+=b[i];
						}else{
							sum+=a[i];
						}
					}
				}
			}
		}
		cout<<sum;
	}
	return 0;
}


