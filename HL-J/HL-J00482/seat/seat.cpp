#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int nz=1,mz=1;
	int ns=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;a[i]!=ns;i++){
		if(mz%2==1){
			if(nz<n){
				nz++;
			}
			else{
				mz++;
			}
		}
		else{
			if(nz>1){
				nz--;
			}
			else{
				mz++;
			}
		}
	}
	cout<<mz<<" "<<nz;
	return 0;
}