#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k;
int s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int xingzhib=1,xingzhic=1;
	int sxingzhib=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) xingzhib=0;
		if(a[i]>255) xingzhic=0;
		if(a[i]==k) sxingzhib++;
	}
	if(xingzhib){
		cout<<sxingzhib;
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]^a[i];
		}
		int l=0;
		int ans=0;
		
		for(int i=1;i<=n;i++){
			for(int j=l;j<=i;j++){
				
				if(abs(s[i]^s[j-1])==k){
					//printf("%d %d %d\n",i,j,i-j+1);
					ans++;
					l=i+1;
					i++;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	/*
	if(xingzhic){
		
	}*/
	return 0;
}
