#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum,t,a,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>t;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>t){
			sum++;
		}
	}
	sum++;
	x=(sum+n-1)/n;
	if(x%2==0){
        cout<<x<<" "<<n-sum+n*(x-1)+1;
    }else{
		cout<<x<<" "<<sum-n*(x-1);
	}
	cout<<endl;
	return 0;
}
