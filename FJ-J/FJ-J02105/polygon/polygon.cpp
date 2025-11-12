#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s,max,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		s=max=0;
		for(int j=1;j<=n-i+1;j++){
			for(int k=j;k<=k+i-1&&k+i-1<=n;k++){
				s+=a[k];
				if(a[k]>max){
					max=a[k];
				}
			}
		}
		if(s/2>max){
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
