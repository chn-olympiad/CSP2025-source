#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int f[110],s[110];
	cin>>n>>m; 
	int d=n*m;
	for(int i=0;i<d;i++){
		cin>>f[i];
	}
	int x=f[0];
	sort(f,f+d);
	int j=0;
	for(int i=d-1;i>=0;i--){
		s[j]=f[i];
		j++;
	}
	int w;
	for(int i=0;i<d;i++){
		if(s[i]==x){
			w=i+1;
		} 
	}
	int c=w/n+1;
	int r=w%n;
	if(r==0){
		r=n;
		c--;
	}
	int z=n+1;
	if(c%2==0){
		r=z-r;
	}
	cout<<c<<" "<<r;
	return 0;
}
