#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[101],e,f,h,k,l,m,n,o;
int g=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	c=a*b;
	if(c==1){
		cout<<1<<" "<<1;
		h=2;
	}
	if(h!=2){
		cin>>e;
		for(int i=1;i<=c-1;i++){
			cin>>f;
			if(e<f){
				g+=1;
			}
		}
		k=g/a;
		l=g%a;
		if(k%2==0){
			if(l==0){
				m=l+1;
				cout<<k<<" "<<m;
			}
			else if (l!=0){
				o=k+1;
				cout<<o<<" "<<l;
			}
		}
		else if(k%2!=0){
			if(l==0){
				cout<<k<<" "<<a;
			}
			else if (l!=0){
				o=k+1;
				n=a-l+1;
				cout<<o<<" "<<n;
			}
		}
	}
	
	
	return 0;
}

