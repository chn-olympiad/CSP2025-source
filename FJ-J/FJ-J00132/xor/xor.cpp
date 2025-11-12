#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500005],num[21],s[21];
void t_num(int n){
	while(n!=0){
		for(int i=20;i>1;i--){
			num[k]=num[k-1]*10;
		}
		num[1]=0;
		if(n%2==1){
			num[1]=1;
		}
		n/=2;
	}
}
void t_s(int n){
	while(n!=0){
		for(int i=20;i>1;i--){
			s[k]=s[k-1]*10;
		}
		s[1]=0;
		if(n%2==1){
			s[1]=1;
		}
		n/=2;
	}
}
void b(){
	for(int i=1;i<21;i++){
		if(num[i]!=s[i])num[i]=1;
		else num[i]=0;
	}
}
int yh(int l,int r){
	for(int i=1;i<=20;i++){
		num[i]=0;
		s[i]=0;
	}
	t_num(a[l]);
	for(int i=l+1;i<=r;i++){
		t_s(a[i]);
		b();
	}
	int z=0;
	for(int i=0;i<20;i++){
		z+=pow(num[i+1],i);
	}
	return z;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yh(i,j)==k){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
