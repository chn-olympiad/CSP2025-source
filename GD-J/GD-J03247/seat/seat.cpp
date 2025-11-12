#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=110;
int a[N];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int num,sum,ans,tot;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=num;i++){
		if(a[i]==sum){
			ans=i;
			break;
		}
	}
	if(ans%n==0){
		cout<<ans/n<<" ";
		if((ans/n)%2==1){
			cout<<n;
		}
		else cout<<1;
		return 0;
	}
	else{
		tot=(ans-(ans%n))/n;
		cout<<tot+1<<" ";
		if((tot+1)%2==1){
			cout<<ans-tot*n;
		}
		else{
			cout<<n-ans+tot*n+1;
		}
		return 0;
	}
	
	
	return 0;
}

