#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){

		cin>>a[i];

	}
	x=a[1];
	sort(a+1,a+1+cnt,cmp);
	int rk;

	for(int i=1;i<=cnt;i++){
		if(a[i]==x){
			rk=i;
			break;
		}
	}


	int num=1;
	int l=1,r=1,p=1;
	while(num<rk){
		if(l+p<=n&&l+p>=1){
			l+=p;	
		}else{
			r++;
			p=-p;
		}
		
		
		num++;
	}
	cout<<r<<" "<<l;
	return 0;
}