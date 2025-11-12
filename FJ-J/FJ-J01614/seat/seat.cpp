#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],bz,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	bz=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==bz)cnt=i;
	}
	int l=cnt/n;
	if(cnt%n==0){
		if(l%2!=0)cout<<cnt/n<<" "<<n;
		else cout<<cnt/n<<" "<<1;
	}
	else{
		if(l%2!=0)cout<<cnt/n+1<<" "<<n+1-cnt%n;
		else cout<<cnt/n+1<<" "<<cnt%n;
	}
	return 0;
} 
