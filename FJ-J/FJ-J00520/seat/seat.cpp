#include<bits/stdc++.h>
using namespace std;
int m,n;
int ansx,ansy;
int pas=1;
int ans;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int x;
	cin>>ans;
	for(int i=0;i<n*m-1;i++){
		scanf("%d",&x);
		if(x>ans)pas++;
	}
	ansx=pas/n;
	if(ansx*n<pas)ansx++;
	if(ansx%2==0){
		ansy=n-(pas%n)+1;
	}else{
		ansy=pas%n;
		if(ansy==0){
			ansy=n;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
