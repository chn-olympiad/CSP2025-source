#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,k,cnt;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		long long sum=a[i];
		if(a[i]==k){
			if(r<i){
				cnt++;
			}
			l=i,r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				if(i>r){
					if(l!=0&&r!=0){
						cnt++;
					}
					l=i,r=j;
				}else if(j<=r){
					l=i,r=j;
				}
				break;
			}	
		}
	}
	if(l!=0&&r!=0){
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}