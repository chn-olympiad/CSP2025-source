#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,a=1,b=1,cc=1,dd=1,ans,ans1=1;cin>>n>>m;
	vector<int>A(n*m+1);
	for(int i=1;i<=n*m;i++)cin>>A[i];
	ans=A[1];
	sort(A.begin(),A.end());
	for(int i=1;i<=n*m;i++){
		if(ans==A[i])break;
		ans1++;
	}
	ans1=n*m-ans1;
	for(int i=1;i<=ans1;i++){
		if(a==1&&b%2==1){
			dd=1;cc=1;
		}
		if(a==1&&b%2==0){
			dd=1;cc=0;
		}
		if(a==n&&b%2==1){
			dd=1;cc=0;
		}
		if(a==n&&b%2==0){
			dd=0;cc=1;
		}
		if(cc==1){
			if(dd==1)a++;
			if(dd==0)a--;
		}
		if(cc==0){
			b++;
		}
	}
	cout<<b<<' '<<a;
	return 0;
}