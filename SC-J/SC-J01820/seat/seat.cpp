#include<bits/stdc++.h>
using namespace std;
long long score[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>score[i];
	}
	long long r=score[1];
	sort(score+1,score+1+n*m,greater<long long>());
	long long loa=0;
	for(long long i=1;i<=n*m;i++){ 
		if(score[i]==r){
			loa=i;
			break;
		}
	}
	long long ans1=(loa+n-1)/n;
	cout<<ans1<<" ";
	long long ans2=loa%n;
	if(ans2==0) ans2=n;
	if(ans1%2==0) ans2=n+1-ans2;
	cout<<ans2;
}
/*
4 5
86 100 99 98 97 96 95 94 93 92 91 90 89 88 87 85 84 83 82 81

4 5
86 100 93 92 85 84 99 94 91 83 98 95 90 87 82 97 96 89 88 81
*/
