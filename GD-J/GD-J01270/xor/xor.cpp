#include<bits/stdc++.h>
using namespace std;
int flag=0;
void solvet(int *a,int* b,int n,int k){
	sort(a,a+n);
	if(a[0]==a[n-1]&&a[0]==1){
		flag=1;
		if(k>1){
			cout<<0;
		}else if(k==1){
			cout<<n;
		}else if(k==0){
			cout<<n/2;
		}
		return;
	}
	else if(a[0]==0&&a[n-1]==1){
		flag=1;
		if(k>1) cout<<0;
		if(k==1) {
			int ans=0;
			for(int i=0;i<n;i++){
				if(b[i]==1) ans++;
			}
			cout<<ans;
		}if(k==0){
			int ans=0;
			for(int i=0;i<n;i++){
				if(b[i]==0){
					ans++;
				}
				if(b[i]==1&&b[i+1]==1){
					ans++;
				}
			}
			flag=1;
			return;
		}
	}
}
int a[500001],b[500001],xors[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans,n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		xors[0]=a[0];
		b[i]=a[i];
		xors[i]=a[i]^xors[i-1];
	}
	solvet(b,a,n,k);
	if(flag==1){
		return 0;
	}
	int l=0,r=0,dx=a[l];ans=0;
	while(r<n){
		dx=xors[r]^xors[l];
		if(l==0){
			dx=xors[r];
		}
		if(dx==k||(l==r&&a[l]==k)){
			ans++;
			l=r;
			r=l;
		}
		if(dx>k){
			while(dx>k){
				l++;
				dx=xors[l]^xors[r];
			}
			continue;
		}
		r++;
	}
	
	cout<<ans;
}//É¶Ñ½ÕâÊÇ 
