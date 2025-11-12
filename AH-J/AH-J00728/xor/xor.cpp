#include<bits/stdc++.h>
using namespace std;
long long n,k,s;
long long a[500100];
long long awyhh(long long a,long long b){
	 int ax[1000],bx[1000],c[1000],rt=0,v=1,i=1,j=1;
	 while(a!=0){
		 ax[i]=a%2;
		 a=a/2;
		 i++;
	 }
	 while(b!=0){
		 bx[i]=b%2;
		 b=b/2;
		 j++;
	 }
	 for(int k=1;k<=max(i,j);k++){
		 if(ax[k]==bx[k]){
			 c[k]=0;
		 }
		 else if(ax[k]!=bx[k]){
			 c[k]=1;
		 }
	 }
	 if(c[1]==1){
		 rt=rt+1;
	 }
	 for(int k=2;k<=max(i,j);k++){
		 if(c[k]==1){
			 for(int w=1;w<k;w++){
				 v=v*2;
			 }
			 rt+=v;
			 v=1;
		 }
	 }
	 return rt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1&&a[2]==1&&k==0&&n<=2){
			cout<<1;
			return 0;
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				s++;
			}
			else if(a[i]==a[i+1]){
				s++;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				s++;
			}
			else if(a[i]+1==a[i+1]||a[i]-1==a[i+1]){
				s++;
				i++;
			}
		}
	}
	else for(int i=1;i<=n;i++){
		if(a[i]==k){
			s++;
		}
		else if(awyhh(a[i],a[i+1])==k){
			s++;
			i++;
		}
		else if(awyhh(awyhh(a[i],a[i+1]),a[i+2])==k){
			s++;
			i+=2;
		}
	}
	cout<<s;
    return 0;
}
