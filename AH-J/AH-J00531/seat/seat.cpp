#include<bits/stdc++.h>
using namespace std;
struct ks{
	int cj;
	int wz;
};
bool cmp(ks a,ks b){
	return a.cj>b.cj;
}
ks a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,n,m;
	cin>>x>>y;
	cin>>a[1].cj;
	a[1].wz=1;
	n=a[1].cj;
	for(int i=2;i<=x*y;i++){
		cin>>a[i].cj;
		a[i].wz=i;
	}
	sort(a+1,a+1+x*y,cmp);
	for(int i=1;i<=x*y;i++){
		if(a[i].cj==n){
			m=i;
		}
	}
	int b=m/x+1;
	if(m%x==0){
		cout<<m/x<<" ";
		if((m%x+1)%2==0){
			if(m%x==0){
				cout<<1;
				return 0;
			}
		}
		else {
			cout<<x;
			return 0;
		}
	}
	else{
		cout<<b<<" ";
	}
	if(b%2==0){
		if(m%x==0){
			cout<<1;
			return 0;
		}
		cout<<x-m%x+1;
		return 0;
	}
	else if(b%2==1){
		if(m%x==0){
			cout<<x;
			return 0;
		}
		cout<<m%x;
		return 0;
	}
	return 0;
}
