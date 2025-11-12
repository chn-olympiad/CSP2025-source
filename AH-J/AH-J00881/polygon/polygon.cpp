#include<bits/stdc++.h>
using namespace std;
const long long Mod=998224353;
int A[5500];
long long B[5500];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	sort(A+1,A+1+N);
	if(N==3){
		if(A[1]+A[2]>A[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(A[1]==A[N]){
		long long cnt=pow(2,N)-1-N-N*(N-1)/2;
		cnt=cnt%Mod;
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=N;i++)
		B[i]=A[i]+B[i-1];
	long long cnt=0;
	for(int i=1;i<=N;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	for(int i=1;i<=N;i++)
		cout<<B[i]<<" ";
	cout<<endl;
	for(int i=1;i<=N-2;i++){
		for(int j=i+2;j<=N;j++){
			long long sum=B[j]-B[i-1];
			if(sum>A[j]*2) cnt=(cnt+1)%Mod;
		}
	}
	cout<<cnt;
	return 0;
}
