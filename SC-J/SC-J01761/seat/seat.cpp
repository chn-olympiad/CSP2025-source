#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110],x,y,cnt;
bool cmp(int xx,int yy){
	return xx>yy;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			cnt=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cnt=i;
			break;
		}
	}
	x=cnt/n;
	if(cnt%n==0){
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
		
	}else{
		x++;
		if(x%2==0){
			y=n-(cnt%n)+1;
			
		}else{
			y=cnt%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}