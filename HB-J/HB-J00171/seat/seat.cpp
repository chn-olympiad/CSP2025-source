#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int x=a[1],sb;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		if(a[i]==x){
			sb=i;
		}
	}
	if((sb/n)%2==0&&sb%n!=0){
			cout<<sb%n<<' '<<(sb/n)+1;
	}else if((sb/n)%2!=0&&sb%n==0){
			cout<<sb/n<<' '<<n;
	}else if((sb/n)%2==0&&sb%n==0){
			cout<<1<<' '<<sb/n;
	}else{
		cout<<1<<' '<<(sb/n)+1;
	}

	
	return 0;
}
