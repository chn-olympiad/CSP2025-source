#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005],k;
int xr(int num[],int l,int s){
	int e[n];
	for(int i=l;i<s;i++) e[i]=num[i];
	int ans=0;
	int m=e[l];
	for(int i=l+1;i<s;i++) m=max(m,e[i]);
	for(int i=log2(m);i>=0;i--){
//		printf("i:%d,pi:%d,ans=%d\n",i,(int)pow(2,i),ans);
		bool b=0;
		for(int j=l;j<s;j++){
			if(e[j]>=pow(2,i)){
				e[j]-=pow(2,i);
				b=(b||1)&&!(b&&1);
			}else b=(b||0)&&!(b&&0);
		}
		if(b) ans+=pow(2,i);
//		printf("q1:%d,q2:%d,ans:%d\n",(int)q1,(int)q2,ans);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	int l=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			if(xr(a,j,i)==k){
//				cout<<j<<" "<<i<<endl;
				l=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
