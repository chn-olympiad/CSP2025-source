#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	z=a[1];
	int x=1,y=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i] == z){
			cout<<y<<" "<<x;
			return 0;
		}
		else{
			if(y%2==1){
				if(x!=n){
					x+=1;
				}
				else{
					y+=1;
				}
			}
			else if(y%2==0){
				if(x!=1){
					x-=1;
				}
				else{
					y+=1;
				}
			}
		}
	}
}
