#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],b[N],c[N];
bool cmp(int n,int m){
	for(int i=n-1;i<=m;i++){
		if(c[i]==1) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	bool f1=1,f2=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=0;
		if(a[i]!=1&&a[i]!=0) f2=0;
		c[i]=0;
	}
	if(f1==1){
		if(k>1) cout<<"0";
		else if(k==1) cout<<n;
		else cout<<n/2;
	}
	else if(f2==1){
		if(k>1) cout<<"0";
		else if(k==1){
			long long s=0;
			for(int i=2;i<=n;i++){
				if(a[i]!=a[i-1]&&a[i]>=0&&a[i-1]>=0){
					s++;
					i++;
				}
				if(a[i]==a[i-1]&&a[i-2]==a[i-3]&&i>=4){
					s++;
					i++;
					a[i]=-1;
					a[i-1]=-2;
					
				}
			}
			cout<<s;
		}
		else{
			long long s=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]){
					s++;
					i++;
				}
				if(a[i]!=a[i-1]&&a[i-2]!=a[i-3]){
					s++;
					i++;
					a[i]=0;
					a[i-1]=0;
					
				}
			}
			cout<<s;
		}
	}
	else if(k==0){
		long long s=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]){
					s++;
					i++;
				}
				if(a[i]!=a[i-1]&&a[i-2]!=a[i-3]){
					s++;
					i++;
					a[i]=0;
					a[i-1]=0;
					
				}
			}
		cout<<s;
	}
	else{
		for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(b[j]^b[i-1]==k&&cmp(i,j)==1){
					s++;
					for(int k=i;k<=j;k++) c[i]=1;	
				}
			}
		}
		cout<<s;
	}
	return 0;
}
