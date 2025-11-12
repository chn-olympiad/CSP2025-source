#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
bool A(int a[],int n){
	bool b=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) b=false;
	}
	return b;
}
bool B(int a[],int n){
	bool b=true;
	for(int i=1;i<=n;i++){
		if(a[i]>1) b=false;
	}
	return b;
}

int n,k,a[N],ans,ans2[N],num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(A(a,n)){
		ans=n/2; 
		cout<<ans;
		return 0;
	}
	if(B(a,n)){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) ans++;
			}		
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}					
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		num=a[i];
		for(int j=i+1;j<=n;j++){
			num^=a[j];
			if(num==k){ans2[i]++; num=a[j+1];}
		}
		if(ans2[i]==0&&a[i]==k) ans2[i]++;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,ans2[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}