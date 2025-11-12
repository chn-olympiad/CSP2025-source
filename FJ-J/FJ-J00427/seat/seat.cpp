#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,sc,w;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			sc=i;
			break;
		}
	}
	if(sc%n==0){
		w=sc/n;
		cout<<sc/n<<" ";
	}
	else{
		w=sc/n+1; 
		cout<<sc/n+1<<" ";
	}
	if(w%2==1&&sc%n==0)cout<<n;
	else if(w%2==1)cout<<sc%n;
	else if(w%2==0&&sc%n==0)cout<<1;
	else cout<<n-sc%n+1;
	return 0;
}
