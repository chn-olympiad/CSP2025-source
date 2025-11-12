#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
int n,m;
int a[MAXN];
int f[MAXN];
int x=1,y=1;
bool dow=0;
int mod(int a,int b){
	if(a%b==0){
		return a/b;
	}else{
		return a/b+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) r=a[i]; 
	}
	int f;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[n*m-i+1]==r){
			f=i;
		}
	}
	int rr=mod(f,n);
	int rrr;
	if(rr%2==0){
		if(f%n==0){
			rrr=1;
		}else{
			rrr=n+1-f%n;
		}
	}
	else if(rr%2==1){
		if(f%n==0){
			rrr=n;
		}else{
			rrr=f%n;
		}
	}
	cout<<rr<<' '<<rrr;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

