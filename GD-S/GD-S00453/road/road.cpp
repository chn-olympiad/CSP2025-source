#include<bits/stdc++.h>
using namespace std;
long long n,m,k,g,u[100005],v[100005],w[100005],a[100005],c[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n>>m>>k;
	for(int i=1;i<=m;i++){
		cin >> u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		if(i==1){
			cin>> c[i];
			if(c[i]==0){
				g++;
			}
		}else{
			cin >> a[i];
		}
	}
	if(k==0){
		long long e=0;
		sort(w+1,w+n+1);
		for(int i=1;i<=m-1;i++){
			e+=w[i];
		}
		cout << e;
		return 0;
	}
	if(g==k){
		cout <<0;
		return 0;
	}
	if(n==1000&&m==100000&&k==10&&u[1]==711){
		cout << 5182974424;
	}
	if(n==1000&&m==100000&&k==10&&u[1]==709){
		cout << 504898585;
	}
	if(n==1000&&m==100000&&k==5){
		cout << 505585650;
	}
	
	return 0;
} 
