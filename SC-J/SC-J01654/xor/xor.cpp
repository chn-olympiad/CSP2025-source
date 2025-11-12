#include<bits/stdc++.h>
using namespace std;
const long long N=1e5;
long long a[5*N+3];
int b[5*N+3];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int flag=0,m1=0,m2=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]==0) m1++;
		if(a[i]==1&&a[i-1]==1){
			m1++;
			i++;
		}
		if((a[i]==1&&a[i-1]==0)||(a[i]==0&&a[i-1]==1)){
			m2++;
			b[i]=1;
			b[i-1]=1;
			i++;
		}
		if(a[i]==1&&b[i]==0){
			m2++;
		}
	}
	if(k==0){
		if(flag==0){
			cout<<n/2;
		}
		else{
			for(long long i=1;i<=n;i++){
			if(a[i]!=1){
				flag=1;
			}
			if(a[i]==0) m1++;
			if(a[i]==1&&a[i-1]==1){
				m1++;
				i++;
			}
			
			}	
		}
	}
	else if(k==1){
		for(long long i=1;i<=n;i++){
			if((a[i]==1&&a[i-1]==0)||(a[i]==0&&a[i-1]==1)){
				m2++;
				b[i]=1;
				b[i-1]=1;
				i++;
			}
			if(a[i]==1&&b[i]==0){
				m2++;
			}
		} 
		cout<<m2;
	}
	
	
	
	return 0;	
}