#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,f[N],p,c;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	p=f[1];
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f[i]==p){
			c=i;
		}
	}
	int x=c/n,y=c%n;
	if(c%n!=0)x+=1;
	if(!y){
		if(x%2==1)y=n;
		else y=1;
		cout<<x<<" "<<y;
	}else{
		if(x%2==1){
			cout<<x<<" "<<y;
		}else{
			cout<<x<<" "<<n-y+1;
		}
	}
	return 0;
}
