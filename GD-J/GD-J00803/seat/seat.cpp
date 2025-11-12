#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int a1;
int x,y;
bool cmd(int a,int b){
	return a>b;
}



int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}a1=a[1];
	sort(a+1,a+1+n*m,cmd);
	for(int i=1;i<=n*m;i++){
		if(a1==a[i]){
			x=(i-1)/n+1;
			if(x%2){
				y=(i-1)%n+1;
			}else{
				y=n-(i-1)%n;
			}
			break;
		}
	}cout<<x<<" "<<y;
	
	return 0;
} 
