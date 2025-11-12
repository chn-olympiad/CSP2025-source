#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[3]={1,-1};
bool cmp(int q,int w){
	return w<q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int as=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,s=0;
	for(int i=1;i<=n*m;i++){
		if(as==a[i]){
			cout<<y<<" "<<x;
		}
		x+=b[s];
		if(x==n+1||x==0){
			s=(s+1)%2;
			y++;
			x+=b[s];
		}
		
	}
} 
