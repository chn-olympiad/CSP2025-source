#include<bits/stdc++.h>
using namespace std;
const int N=207;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	int q=0;
	for(int i=1;i<=z;i++){
		cin>>a[i];
		if(i==1)q=a[i];
	}
	sort(a+1,a+z+1,cmp);
	int k=0;
	for(int i=1;i<=z;i++){
		if(a[i]==q){
			k=i;
			break;
		}
	}
	int l,h;
	if(k%n==0)l=k/n;
	else l=k/n+1;
	if(l%2==1){
		if(k%n==0)h=n;
		else h=k-k/n*n;
	}
	else{
		if(k%n==0)h=1;
		else h=n-k+k/n*n+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
