#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int a[10000860];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)k=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ans=i;
			break;
		}
	}
	int l=ans/n;
	if(ans%n>=1)l++;
	int h;
	if(l%2==1){
		if(ans%n==0){
			h=n;
		}else{
			h=ans%n;
		}
	}else{
		if(ans%n==0){
			h=1;
		}else{
			h=n-ans%n+1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
} 
