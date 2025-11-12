#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
bool cmp(long long a,long long b){
	return a<b;
}
long long a[1010],v[1010][1010],ans=0,sum=0,f=0;
int main(){
	freopen("road1.in","r",stdin); 
	freopen("road.out","w",stdout); 
	long long n,m,k;
	cin>>n>>m>>k;
	memset(a,sizeof(a),0);
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>a[++sum];
	}for(int i=1;i<=k;i++){
		int y;
		cin>>y; 
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			a[++sum]=x+y;
		}
	}sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}cout<<ans;
	return 0;
} 
