#include<bits/stdc++.h>
using namespace std;
int n,m,x,hs,ls,t;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			ls=i/n;
			hs=i%n;
			t=ls+(hs==0?0:1);
			printf("%d ",t);
			if(hs==0){
				if(t%2==1){
					cout<<n;
				}else{
					cout<<1;
				}
			}else{
				if(t%2==1){
					cout<<hs;
				}else{
					cout<<n-hs+1;
				}
			}
		}
	}
} 
