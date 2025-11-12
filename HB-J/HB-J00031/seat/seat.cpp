#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],i;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int N=n*m;
	int n1;
	for(i=1;i<=N;i++)cin>>a[i];
	n1=a[1];
	sort(a+1,a+1+N,cmp);
	int ans=0;
	for(i=1;i<=N;i++){
		ans++;
		if(a[i]==n1)break;
	}
	if(ans%n!=0){
	cout<<ans/n+1<<" ";
	if((ans/n+1)%2==0)cout<<n-(ans%n)+1;
	else cout<<ans%n;
	}
	else{
		cout<<ans/n<<" "<<n;
	}
	return 0;
}
