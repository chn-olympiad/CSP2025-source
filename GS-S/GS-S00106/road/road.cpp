#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0;
char a[100005][3],b[100005][3];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long j=1;j<=3;j++){
		for(long long i=1;i<=n;i++){
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
	    }
	}
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n+1;j++){
			cin>>b[i];
		}
	}
	if(k==0){
		for(long long i=1;i<=n;i++){
			sum=sum+a[i][3];
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
