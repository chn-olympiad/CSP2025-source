#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000][1000],c[1010],sum=0,h=1,l=1,ans=0;
bool cmp(int x,int y){
	if(x>y)return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(register int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int r=c[1];
	//cout<<r<<endl;
	sort(c+1,c+n+1,cmp);
	for(register int i=1;i<=n*m;i++){
	//	cout<<c[i]<<endl;
		if(c[i]>r)sum++;
	}
	//cout<<sum<<endl;
	if(sum<=n)cout<<l<<" "<<h+sum;
	else if(n=1)cout<<l+sum<<" "<<1;
	else{
		
	}
	return 0;
}
