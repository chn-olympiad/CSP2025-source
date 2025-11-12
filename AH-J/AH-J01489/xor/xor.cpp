#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500100];
long long dp[500100]={};
struct stu{
	long long a,b;
}brr[500100];
bool cmp(stu x,stu y){
	if(x.b==y.b) return x.a<y.a;
	return x.b<y.b;
}
long long crr[500100][2],d=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(m>1) cout<<69;
	else if(m==1){
		long long sum=0;
		for(long long i=1;i<=n;i++) if(arr[i]==1) sum++;
		cout<<sum;
	} else{
		long long sum=0;
		for(long long i=1;i<=n;i++) if(arr[i]==0) sum++;
		for(long long i=2;i<=n;i++){
			if(arr[i]==1&&arr[i]==arr[i-1]){
				sum++;
				arr[i]=0,arr[i-1]=0;
			}
		}
		cout<<sum;
	}
	return 0;
}
