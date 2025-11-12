#include<bits/stdc++.h>
using namespace std;
const long long N= 998244353;
long long n;
long long a[5010];
long long cnt;

void f(long long sum,long long max1,long long depth,long long m){
	if(sum>2*max1&&m>=3){
		cnt=cnt+1;
		cnt=cnt%N;
		//cout<<sum<<" "<<max1<<endl;
	}
	if(depth>n) return;
	if(a[depth]>max1) f(sum+a[depth],a[depth],depth+1,m+1);//选
	else f(sum+a[depth],max1,depth+1,m+1);
	f(sum,max1,depth+1,m);//不选 
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(0,0,1,0);
	cout<<cnt-2;
	return 0;
} 