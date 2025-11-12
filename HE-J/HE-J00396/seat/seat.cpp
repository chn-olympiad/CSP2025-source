#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int b[n*m];
	for(int i=0;i<n*m;i++)cin>>b[i];
	int c=b[0],d=1,e=1;
	sort(b,b+(n*m),cmp);
	bool f=1;
	for(int i=0;i<n*m;i++){
		if(b[(e-1)*n+d-1]==c && e%2==1){
			cout<<e<<' '<<d;
			break;
		}
		else if(b[(e-1)*n+n-d]==c && e%2!=1){
			cout<<e<<' '<<d;
			break;
		}
		else{
			if(f){
				if(d==n){
					f=0;
					e++;
				}
				else d++;
			}
			else{
				if(d==1){
					f=1;
					e++;
				}
				else d--;
			}
		}
	}
	
	
	
	
	
	return 0;
}
