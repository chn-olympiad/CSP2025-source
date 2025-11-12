#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,tmp,h,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			if((i/n)%2==1){
				if(i%n!=0){
					l=i/n+1;
					tmp=i-n*(l-1);
					h=n+1-tmp;
				}
				else if(i%n==0){
					l=i/n;
					h=n;
				}
			}
			if((i/n)%2==0){
				if(i%n!=0){
					l=i/n+1;
					tmp=i-n*(l-1);
					h=tmp;
				}
				else if(i%n==0){
					l=i/n;
					h=1;
				}
			}
		}
	}
	cout<<l<<" "<<h;
}
