#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[5010],s[1025];
int solve3(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) if(a[i]+a[j]>a[x]) num++;
	return num;
}int solve4(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) if(a[i]+a[j]+a[k]>a[x]) num++;
	return num;
}int solve5(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) for(int l=k+1;l<x;l++) if(a[i]+a[j]+a[k]+a[l]>a[x]) num++;
	return num;
}int solve6(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) for(int l=k+1;l<x;l++) for(int m=l+1;m<x;m++) if(a[i]+a[j]+a[k]+a[l]+a[m]>a[x]) num++;
	return num;
}int solve7(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) for(int l=k+1;l<x;l++) for(int m=l+1;m<x;m++) for(int p=m+1;p<x;p++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[p]>a[x]) num++;
	return num;
}int solve8(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) for(int l=k+1;l<x;l++) for(int m=l+1;m<x;m++) for(int p=m+1;p<x;p++) for(int v=p+1;v<x;v++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[p]+a[v]>a[x]) num++;
	return num;
}int solve9(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) for(int l=k+1;l<x;l++) for(int m=l+1;m<x;m++) for(int p=m+1;p<x;p++) for(int v=p+1;v<x;v++) for(int c=v+1;c<x;c++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[p]+a[v]+a[c]>a[x]) num++;
	return num;
}int solve10(int x){
	int num=0;
	for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) for(int k=j+1;k<x;k++) for(int l=k+1;l<x;l++) for(int m=l+1;m<x;m++) for(int p=m+1;p<x;p++) for(int v=p+1;v<x;v++) for(int c=v+1;c<x;c++) for(int b=c+1;b<x;b++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[p]+a[v]+a[c]+a[b]>a[x]) num++;
	return num;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		sum=max(sum,a[i]);
	}if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
	}else if(sum==1){
		for(int i=1;i<=n;i++){
			sum*=2;
			sum%=998244353;
		}cout<<(sum+998244353-n*(n+1)/2-1)%998244353;	
	}else{
		sum=0;
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++) sum+=solve3(i);
		for(int i=4;i<=n;i++) sum+=solve4(i);
		for(int i=5;i<=n;i++) sum+=solve5(i);
		for(int i=6;i<=n;i++) sum+=solve6(i);
		for(int i=7;i<=n;i++) sum+=solve7(i);
		for(int i=8;i<=n;i++) sum+=solve8(i);
		for(int i=9;i<=n;i++) sum+=solve9(i);
		for(int i=10;i<=n;i++) sum+=solve10(i);
		cout<<sum%998244353;
	}return 0;
}
