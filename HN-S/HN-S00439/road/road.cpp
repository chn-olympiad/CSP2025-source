#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct q{
	long long u;
	long long v;
	long long w;
};
struct p{
	long long o;
	long long z[10010];
};
long long a[1000010],x[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	q a;
	for(int i = 0;i<m;i++){
		cin>>a.u>>a.v>>a.w;
	}
	p x;
	for(int i = 0;i<k;i++){
		cin>>x.o;
		for(int j = 0;j<n;j++){
			cin>>x.z[j]; 
		}
	}
	//
	//
	for(int i = 0;i<m;i++){
		cout<<a.u<<" "<<a.v<<" "<<a.w<<endl;
	}

	for(int i = 0;i<k;i++){
		cout<<x.o<<" ";
		for(int j = 0;j<n;j++){
			cout<<x.z[j]<<" "; 
		}
		cout<<endl;
	}
	return 0;
}
