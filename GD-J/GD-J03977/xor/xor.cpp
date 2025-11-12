#include<bits/stdc++.h>
using namespace std;
int n,A[500005],cnt,k;
int yh(int a,int b){
	int x[25]={0},y[25]={0},p=1,c1=0,c2=0;
	if(a==0 && b==0) return 1;
	while(a>0){
		x[p++]=a%2;
		a/=2;
		c1+=1;
	}
	p=1;
	while(b>0){
		y[p++]=b%2;
		b/=2;
		c2+=1;
	}
	int sum=0;
	for(int i=1;i<=max(c1,c2);i++){
		if(x[i]+y[i]==0) sum+=pow(2,i-1);
		else sum+=(x[i]+y[i])%2*pow(2,i-1);
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(A[i]==0) cnt++;
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(A[i]==k){
			cnt++;
			s=0;
		}
		else if(s==k){
			cnt++;
			s=0;
		}
		else s=yh(s,A[i]);
	}
	if(s==k) cnt++;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
