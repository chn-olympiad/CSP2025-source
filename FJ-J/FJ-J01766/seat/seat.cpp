#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],r,s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			s=i;
			break;
		}
	}
	if(s%n==0&&(s/n)%2==1) cout<<s/n<<' '<<n;
	if(s%n==0&&(s/n)%2==0) cout<<s/n<<' '<<1;
	if(s%n!=0&&(s/n+1)%2==1) cout<<s/n+1<<' '<<s-s/n*n;
	if(s%n!=0&&(s/n+1)%2==0) cout<<s/n+1<<' '<<n-(s-s/n*n)+1;
	return 0;
}
