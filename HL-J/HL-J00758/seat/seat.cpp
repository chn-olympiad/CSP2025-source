#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10000000010];
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];	
	}
	for(int i=0;i<n*m;i++){
		if(a[i]>maxn){
			a[i]=maxn;
		}
	}
	
	return 0;
}
