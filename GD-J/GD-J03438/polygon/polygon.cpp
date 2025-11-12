#include<bits/stdc++.h>
using namespace std;
int n,a[6000],b[6000],m[6000],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int j=3;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(b[i]-b[i-j]>2*a[i]){
				cnt++;
				for(int k=1,p=0;k<=i;p++){
					if(b[i]-b[i-j+k]+b[i-j-p]-b[i-j-p-k]>2*a[i]&&i-j-p>=1){
						cnt++;
						if(i-j-p==1){
							k++;
							p=0;
						}
					}
					else break;
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
} 
