#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,s,h,l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}a1=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==a1){
			s=i;
			break;
		}
	}
	l=s/n+1;h=s%n+1;
	if(l%2==0)h=m-s%n;
	
	cout<<l<<" "<<h;
	return 0;
}