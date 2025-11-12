#include <bits/stdc++.h>
using namespace std;
int s[20][20],a[110],b[110];
bool cmp(int x,int y){
	return x>y;
}
int n,m,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	b[1]=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b[1]){
			x=i;
			break;
		}
	}
	if(x==1)cout<<1<<" "<<1;
	else if(x==n*m)cout<<n<<" "<<m;
	else{
		if(((x-1)/m)==0)cout<<1<<" "<<x;
		else if(((x-1)/m)==1)cout<<2<<" "<<m-(x-1)%m;
		else if(((x-1)/m)%2==1)cout<<(x/m)+1<<" "<<m-(x-1)%m;
		else if(((x-1)/m)%2==0)cout<<(x/m)+1<<" "<<(x-1)%m;
	}
	return 0;
}

