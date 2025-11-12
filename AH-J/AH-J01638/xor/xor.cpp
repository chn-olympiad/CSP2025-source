#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int ans;
int cnt;
int f1[500010],f2[500010];
int len;
int check(int a,int b){
	for(int i=0;i<len;i++){
		if(f1[i]<f2[i]){
			if((a>=f1[i]&&a<=f2[i])||(b>=f1[i]&&b<=f2[i]))return 0;
		}
		if(f1[i]<f2[i]){
			if((a<=f1[i]&&a>=f2[i])||(b<=f1[i]&&b>=f2[i]))return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<j&&check(i,j)){
				for(int k=i;k<=j;k++){
					cnt=cnt^a[k];
				}
				if(cnt==k){
					ans++;
					f1[len]=i,f2[len]=j;
					len++;
				}
			}else if(i>=j&&check(i,j)){
				for(int k=j;k<=i;k++){
					cnt=cnt^a[k];
				}
				if(cnt==k){
					ans++;
					f1[len]=i,f2[len]=j;
					len++;
				}
			}
			cnt=0;
		}
	}
	cout<<ans;
	return 0;
}
