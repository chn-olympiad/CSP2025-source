#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	int g[150];
	for(int i=1;i<=z;i++){
		cin>>g[i];
	} 
	int x=g[1];
	sort(g+1,g+z+1);
	int pm;
	for(int i=z;i>=1;i--){
		if(g[i]==x){
			pm=z-i+1;
		}
	}int sh=0;
	int l=pm/n;
	if(pm%n>0){
		l++;
		sh=pm%n;
	}
	if(sh!=0){
		if(l%2==0){
			cout<<l<<" "<<n-sh+1;
		}else{
			cout<<l<<" "<<sh;
		}
	}else{
		if(l%2==0){
			cout<<l<<" "<<1;
		}else{
			cout<<l<<" "<<n;
		}
	}
	
}
