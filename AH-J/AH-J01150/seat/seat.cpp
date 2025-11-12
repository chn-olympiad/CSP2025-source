#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[15][15];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int N=n*m;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+N,cmp);
	int ni=1,nj=1;
	bool flag=0;
	for(int i=1;i<=N;i++){
		if(r==a[i]){
			cout<<nj<<" "<<ni;
			return 0;
		}
		if(!flag){
			ni++;
			if(ni>n){
				ni=n;
				nj++;
				flag=!flag;
			}
		}
		else{
			ni--;
			if(ni<1){
				ni=1;
				nj++;
				flag=!flag;
			}
		}
	}
	return 0;
}
