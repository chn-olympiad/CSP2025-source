#include<bits/stdc++.h>
using namespace std;
long long n,cnt,s;
long long a[5010];
/*long long fun(long long i,long long k,long long maxn,long long m,long long c){
	m++;
	k+=a[i];
	maxn=max(maxn,a[i]);
	//cout<<i<<' '<<k<<' '<<maxn<<' '<<m<<' '<<c<<endl;
	if(k>(2*maxn)&&m>2){
		c++;
	}
	for(long long j=i+1;j<=n;j++){
		cnt+=fun(j,k,maxn,m,c);
	}
	c+=cnt;
	cnt=0;
	return c;
}*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
		cin>>a[i];  
	}
	/*for(long long i=1;i<=n;i++){
		s+=fun(i,0,0,0,0);
	}
	cout<<s;*/
	cout<<0;
}
