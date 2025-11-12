#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,c,l;
int a[440];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int nm=n*m;
	int s=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	
	if(s%n==0){
		c=s/n;
	}
	else{
		c=s/n+1;
	}
	if(s%n==0){
		int n1=s/n;
		if(n1&1){
			l=n;
		}
		else{
			l=1;
		}
	}
	else{
		if(s<=n){
			l=s;
		}
		else{
			int ll=s%n;
			if(nn&1){
				l=n-ll+1;
			}
			else{
				l=n-ll-1;
			}
		}
	}
	cout<<c<<" "<<l;
	return 0;
}
