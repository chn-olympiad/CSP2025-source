#include<bits/stdc++.h>
using namespace std;
int n,m,scr,spc;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	scr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==scr){
			spc=i;
		}
			
	}
	int x,y;
	if(spc%n==0){
		x=spc/n;
		if(x&1){
			y=n;
		}else{
			y=1;
		}
	}else{
		x=spc/n+1;
		if(x&1){
			y=spc%n;
		}else{
			y=n-spc%n+1;
		}
	}
		
	cout<<x<<' '<<y;
	return 0;
	
} 

