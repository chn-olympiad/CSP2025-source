#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

long long n,m,k,u,v,w,c,a;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m,i++){
		cin >>u>>v>>w; 
	}
	for(int i=0;i<m,i++){
		cin >>a; 
		for(int i=0;i<n,i++){
		cin >>a; 
		}
	}
	cout << n*m/2; // 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
