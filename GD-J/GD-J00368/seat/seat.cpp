#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
//struct cj{
//	int x;
//	int y;
//};
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int g=a[1];
	int w=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=n*m;i>=1;i--){
		if(a[i]==g)w=i;
	//	cout<<a[i]<<"    "<<i<<endl;
	}
//	cout<<w<<"w";
	int k=(w+n+m-1)/(n+m);
	int y=w%(2*n);
//	cout<<k<<"   "<<y<<"\n";
	if(y>=1&&y<=n)cout<<k*2-1<<" "<<y;
	if(y>=n+1&&y<2*n)cout<<k*2<<" "<<2*n+1-y;
	if(y==0)cout<<k*2<<" "<<1;
	return 0;
} 
