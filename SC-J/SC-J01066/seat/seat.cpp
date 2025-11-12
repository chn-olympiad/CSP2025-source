#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110],ans;
int h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int flag=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==flag){
			ans=i;
			break;
		}
	}
	l=ans/n;
	if(ans%n>=1) l++;
	if(l%2){
		if(ans%n==0) h=m;
		else h=ans%n;
	}else h=m-ans%n+1;
	cout<<l<<" "<<h;
	return 0;
}