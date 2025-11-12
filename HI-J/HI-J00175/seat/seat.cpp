#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int sum=m*n;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int xr=a[1],wei=0;
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==xr){
			wei=i;
			break;
		}
	}
	int lie,hang;
	if(wei%m==0){
		lie=wei/m;
	}else{
		lie=wei/m+1;
	}
	if((wei/m+1)%2==1){
		if(wei%m==0){
			hang=m;
		}else{
			hang=wei%m;
		}
	}else{
		if(wei%m!=0){
			int k=wei%m;
		    hang=m-k+1;
		}else{
			hang=m;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
