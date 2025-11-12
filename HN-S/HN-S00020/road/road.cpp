#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,a,b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a;
		sum+=a;
	}
	for(int i=0;i<k;i++){
		cin>>b;
	}
	cout<<sum;
	return 0;
}

