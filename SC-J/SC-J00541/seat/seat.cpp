#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,seat[N],sum,r;
bool cmp(int a,int b){
	return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		cin>>seat[++sum];
	}
	r=seat[1];
	sort(seat+1,seat+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	if(seat[i]==r){
		r=i;
		break;
	}
	int y=r%n,x=r/n;
	if(y)x+=1;
	cout<<x<<' ';
	if(x%2){
		if(!y)cout<<n;
		else cout<<y;
	}
	else{
		if(!y)cout<<1;
		else cout<<n-y+1;
	}
	return 0;
} 