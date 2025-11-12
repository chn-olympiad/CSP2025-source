#include<bits/stdc++.h>
using namespace std;
int x,y,t,k=1,m=0,n=0,g;
int main(){
//	freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>x>>y;
	t=x*y;
	int a[t+1];
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	for(int i=2;i<=t;i++){
		if(a[1]<a[i])k++;
	}
	if(k<=x){
		m=1;
		n=k;
	}
	else{
		if(k%x==0){
			g=k/y;
			m=g;
				if(g%2==0){
					n=y;
				}
			}
		else{
			g=k/y;
			m=g+1;
			if(g%2==0){
				n=k-g*y;
			}
			else{
				n=y+1-(k-g*y);
			}
		}
	}
	cout<<m<<" "<<n<<endl;
	return 0;
}


