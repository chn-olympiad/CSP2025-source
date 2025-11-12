#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int p,int q){
	if(p<q) return 0;
	else return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,y=1,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(y%2==1) x++;
		else x--;
		if(x==n+1) {
			y++;
			x=n;
		}
		if(x==0){
			y++;
			x=1;
		}
		if(a[i]==k){
			cout<<y<<" "<<x<<endl;
			break;
		}
	}
	return 0;
}
