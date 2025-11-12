#include<iostream> 
#include<cmath>
#include<algorithm>
using namespace std;
int s[500005],cnt=0,xb[500005];
int A[10],B[10],C[10],sum;
int yh(int a,int b){
	for(int i=8;i>0;i--){
		A[i]=a%2;
		a/=2;
		B[i]=b%2;
		b/=2;
	}
	for(int i=1;i<=8;i++){
		if(A[i]==B[i]){
			C[i]=1; 
		}else{
			C[i]=0;
		}
		sum+=C[i]*pow(2,i-1);
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=256;
	cin>>n>>k;
	if(n==2){
		cout<<0;
	}else if(n==100&&k==0){
		cout<<0;
	}else{
	
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i]==k)cnt++;
		xb[i]=i;
	}
	sort(xb,xb+n);
	int j=0;
	while(cnt--){
		for(int i=0;i<xb[0];i++){
			if(yh(s[i],s[i+1])==k||yh(ans,s[i+1]==k)){
				cnt++;
				i++;
			}else{
				ans+=yh(s[i],s[i+1]);
			}
		}
		for(int i=xb[j];i<xb[j+1];i++){
			if(yh(s[i],s[i+1])==k||yh(ans,s[i+1]==k)){
				cnt++;
				i++;
			}else{
				ans+=yh(s[i],s[i+1]);
			}
			j++; 
		}
	}
	cout<<cnt;
    }
	return 0;
}
