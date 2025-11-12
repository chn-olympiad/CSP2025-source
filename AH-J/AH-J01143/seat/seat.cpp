#include<bits/stdc++.h>
using namespace std;
int n,m,r,p,a[110];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) p=i;
	}
	long long x,y,w;
	x=y=w=1;
	for(int i=1;i<p;i++){
		if(x==n&&w==1){
			y++;
			w=0;
		}
		else if(x==1&&w==0){
			y++;
			w=1;
		}
		else{
			if(w==1) x++;
			else x--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
