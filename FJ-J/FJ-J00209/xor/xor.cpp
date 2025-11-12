#include<bits/stdc++.h>
using namespace std;
int a[1001];
int to_2(int n){
	int t=0,t1=0;
	while(n){
		t+=n%2;
		n/=2;
		t*=10;
	}
	while(t){
		t1*=10;
		t1+=t%10;
		t/=10;
		
	}
	return t1;
}
int to_10(int n){
	int cs=0,t=0;
	while(n){
		t+=n%10*pow(2,cs);
		cs++;
		n/=10;
	}
	return t;
}
int myyh(int a, int b){
	int c=0,cs=0;
	while(true){
		if(a%10!=b%10) c+=1*pow(10,cs);
		a/=10;
		b/=10;
		cs++;
		if(a==0&&b==0) break;
	}
	return c;
}
int main(){	
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==m) cnt++;
	}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i+1;j<n;j++){
			sum=myyh(sum,a[j]);
			if(to_10(sum)==m) cnt++;
		}
	}
	cout<<cnt;
    return 0;
}

