#include<bits/stdc++.h>
using namespace std;
int n,m,ss[110],c1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){ 
		cin>>ss[i];
	}
	c1 = ss[1];
	for(int i=1;i<=n*m;i++){
		int maxn=0,ain=0;
		for(int j=1 ; j <= n*m ; j++){
			if(ss[j]>maxn){
				maxn = ss[j];
				ain = j;
			}
		}
		ss[ain]=-1;
		if(c1==maxn){
			if(i%m==0) x=i/m;
			else x=i/m +1;
			if(x%2==0){
				if(i%m==0) y=1;
				else y=m-i%m+1;
			}
			else{
				if(i%m==0) y=m;
				else y=i%m;
			}
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
}
