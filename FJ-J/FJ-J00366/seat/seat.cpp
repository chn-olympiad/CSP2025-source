#include<bits/stdc++.h>
using namespace std;
int n,m,x,t,s=0,tx,ty;
bool a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		if(i==1) t=x;
		a[x]=1;
	}
	
	for(int i=100;i>=0;i--){
		if(a[i]){
			s++;
			if(i==t){
				tx=(s+(n-1))/n;
				if(tx%2==1){
					if(s%n==0) ty=n;
					else ty=s%n;
				} 
				else{
					ty=n-(s%n)+1;
				}
				break;
			}
		}
	}
	cout<<tx<<' '<<ty;
}
