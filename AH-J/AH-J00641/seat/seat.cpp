#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],g[11][11],s,z,p=0,d=1,o=0;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=m*n;
	for(int i=0;i<z;i++){
		cin>>a[i];
	}
	s=a[0];
	a[0]=0;
	sort(a,a+z,cmp);
	while(n){
	if(d==1){
			for(int i=0;i<m;i++){
				if(a[o]<s){
					cout<<p+1<<" "<<i+1;
					return 0;
				}
				g[i][p]=a[o];
				o++;
			}
			p++;
			d++;
		}
	if(d==2){
			for(int i=n-1;i>=0;i--){
				if(a[o]<s){
					cout<<p+1<<" "<<i+1;
					return 0;
				}
				g[i][p]=a[o];
				o++;
			}
			p++;
			d--;
		}
	}
	return 0;
}

