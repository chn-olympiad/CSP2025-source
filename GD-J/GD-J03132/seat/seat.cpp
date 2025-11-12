#include<bits/stdc++.h>
using namespace std;
int x[1005];
bool cnm(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>x[i];
	}
	r=x[0];
	sort(x,x+n*m,cnm);
	for(int i=0;i<n*m;i++){
		if(x[i]==r){
			i++;
			if(m%2==0){
				int a=i/m,b=i%(m*2);
				if(i%n==0&&a%2==1){
					i--;
				}
				if(b>n){
					b-=n;
					b=n-b+1;
					a++;
				}
				cout<<a<<" "<<b;
				return 0;
			}else{
				if(i>(m-1)*n){
					int a=m;
					int b=n-(m*n-i);
					cout<<a<<" "<<b;
					return 0;
				}else{
					m--;
					int a=i/m,b=i%(m*2);
					if(i%n==0&&a%2==1){
						i--;
					}
					if(b>n){
						b-=n;
						b=n-b+1;
						a++;
					}
					cout<<a<<" "<<b;
					return 0;
				}
			}
		}
	}
}

