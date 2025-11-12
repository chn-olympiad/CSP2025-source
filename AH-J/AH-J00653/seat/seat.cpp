#include<bits/stdc++.h>
using namespace std;
int a[105],b[13][13],s,w;
int n,m;
int main(){
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	for(int i=n*m;i>=1;i--) for(int j=1;j<i;j++) if(a[j]<a[j+1]) swap(a[j],a[j+1]);
	for(int i=1;i<=n*m;i++) if(a[i]==s) w=i;
	if(w%n!=0&&(w/n+1)%2==1)cout<<w/n+1<<" "<<w%n;
	if(w%n==0&&(w/n+1)%2==1)cout<<w/n<<" "<<n;
	if(w%n==0&&(w/n+1)%2==0)cout<<w/n<<" "<<1;
	if(w%n!=0&&(w/n+1)%2==0)cout<<w/n+1<<" "<<n-w%n+1;
	return 0;
}

