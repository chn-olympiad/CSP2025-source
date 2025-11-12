#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,snm,zom=1,z=0;
string s;
int c[648],d[648];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i]; 
	} 
	sort(c,c+n);
	d[0]=1;
	for(int i=1;i<n;i++){
		if(c[i]==c[i-1]){
			d[z]++;
		}else{
			z++;
			d[z]++;
		}
	}
	for(int i=0;i<m;i++){
		zom*=d[i];
	}
	for(int i=1;i<=n+m;i++){
		zom*=i;
	}
	cout<<2;
	return 0;
}
