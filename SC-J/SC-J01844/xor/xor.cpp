#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],k,num1[25],num2[25];

void zh1(int x){
	if(x==0) return;
	int s=1,cf=0;
	while(s<=x){
		s*=2;
		cf++;
	}
	s/=2;cf--;
	num1[cf]=1;
	zh1(x-s);
}
void zh2(int x){
	if(x==0) return;
	int s=1,cf=0;
	while(s<=x){
		s*=2;
		cf++;
	}
	s/=2;cf--;
	num2[cf]=1;
	zh2(x-s);
}

int yh(int a,int b){
	zh1(a);zh2(b);
	int ans=0;
	for(int i=0;i<25;i++){
		if(num1[i]==num2[i]) ans+=0;
		else ans+=pow(2,i);
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0,sum;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=yh(a[1],a[2]);
	for(int i=3;i<=n;i++){
		if(sum==k){
			cnt++;
			sum=0;
		}
		yh(sum,a[i]);
	}
	cout<<cnt;
	return 0;
}