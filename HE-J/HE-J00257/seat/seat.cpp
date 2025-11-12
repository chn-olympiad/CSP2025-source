#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,R=0,l=0,h=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			if(i%n==0) l=i/n;
			else l=i/n+1;
			if(l%2!=0){
				h=i%n;
				if(h==0) h=n;
			}
			else if(l%2==0){
				h=n-i%n+1;
				if(h>n) h=1;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
