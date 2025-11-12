#include<bits/stdc++.h>
using namespace std;
const int N=201;
long long n,m,a[N],ans[20][20],d,b,nx=1,ny=1,t;
bool boo=true,c=false;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	d=n*m;
	for(long long i=1;i<=d;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+d+1,cmp);
	for(long long i=1;i<=d;i++){
		if(ny==n+1){
			boo=false;
			nx++;
			ny=n;
		}
		if(ny==0){
			boo=true;
			nx++;
			ny=1;
		}
		if(a[i]==t){
			cout<<nx<<" "<<ny;
			break;
		}
		if(boo) ny++;
		if(!boo) ny--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
