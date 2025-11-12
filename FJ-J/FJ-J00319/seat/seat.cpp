#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
map<int,int>b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		b[a[i]]=i;
	t=b[t];
	if(t%n==0){
		if((t/n)%2==1)
			cout<<t/n<<" "<<n;
		else
			cout<<t/n<<" "<<1;
	}
	else{
		if((t/n+1)%2==1)
			cout<<t/n+1<<" "<<t%n;
		else
			cout<<t/n+1<<" "<<n-(t%n)+1;
	}
	return 0;
}

