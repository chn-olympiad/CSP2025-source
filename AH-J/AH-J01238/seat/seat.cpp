#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int u=x/n,v=x%n;
	if(v)u++;
	else{
		cout<<u<<" "<<n<<"\n";
		return 0;
	}
	if(u%2!=0){
		cout<<u<<" "<<v<<"\n";
	}else{
		cout<<u<<" "<<n-v+1<<"\n";
	}
	return 0;
}
