#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,sum=0;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	for(int i=2;i<=x;i++){
		if(a[i]>a[1]){
			sum++;
		}
	}
	bool flag=true;
	if((sum/n)%2==0){
		flag=true;
	}
	else{
		flag=false;
	}
	if(sum%n==0){
		if(flag){
			cout<<sum/n+1<<' '<<1;
		}
		else{
			cout<<sum/n+1<<' '<<n;
		}
	}
	else if(sum%n!=0){
		if(flag){
			cout<<sum/n+1<<' '<<sum%n+1;
		}
		else{
			cout<<sum/n+1<<' '<<n-(sum%n);
		}
	}
	cout.flush();
	return 0;
}
