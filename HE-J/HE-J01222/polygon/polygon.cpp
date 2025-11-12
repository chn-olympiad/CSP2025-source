#include <bits/stdc++.h>
using namespace std;
long long N;
long long A[5005];
long long Sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)cin>>A[i];
	for(int i=1;i<N;i++){
		Sum+=i;
	}
	cout<<Sum-1;
	return 0;
}
