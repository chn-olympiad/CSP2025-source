#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=1,k=1;
	int ni=1,nj=1;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int d=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			cout<<nj<<" "<<ni;
			break;
		}
		if(n==1&&m==1){
			cout<<1<<" "<<1;
			break;
		}
		if(ni==n&&k==1){
			nj++;
			p^=1;
			k=0;
		}
		else if(ni==1&&k==1&&i!=1){
			nj++;
			p^=1;
			k=0;
		}
		else if(p){
			ni++;
			k=1;
		}
		else if(!p){
			ni--;
			k=1;
		}
	}
	return 0;
}