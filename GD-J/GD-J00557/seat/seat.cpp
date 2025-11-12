#include<bits/stdc++.h>
using namespace std;
bool o(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0,p=1;
	cin>>n>>m;
	int u=n*m;
	int a;
	int b[u];
	for(int i=0;i<u;i++){
		cin>>b[i];
	}
	a=b[0];
	sort(b,b+u,o);
	for(int i=0;i<u;i++){
		
		l=i/n+1;
		if(l%2==0){
			if(i%n==0){
				p++;
			}
			p--;
		}
		else{
			if(i%n==0){
				p--;
			}
			p++;
		}
		if(b[i]==a){
			break;
		}
		
		
	}
	cout<<l<<" "<<p;
	
} 
