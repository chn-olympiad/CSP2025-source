#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum1=0,sum2=0,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sum1++;
		}if(a[i]==0){
			sum2++;
		}
	}
	if(k==0){
		if(sum2==0){
			cout<<sum1/2;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					s++,a[i]=0,a[i+1]=0;
				}
			}cout<<sum2+s;
		}
	}else if(k==1){
		s=0;
		for(int i=1;i<=n;i+=2){
			if(a[i]+a[i+1]==1){
				s++,a[i]=-1,a[i+1]=-1;
			}
		}cout<<s;
	}return 0;
}
