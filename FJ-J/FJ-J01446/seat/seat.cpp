#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,ans,h,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("seat3.in","r",stdin);
//	freopen("seat3.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			ans=a[1];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(ans==a[i]){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0){
		l=cnt/n;
	}else{
		l=cnt/n+1;
	}
	if(l%2==1){
		h=cnt%n;
		if(h==0){
			h=n;
		}
	}else{
		if(cnt%n==0){
			h=1;
		}else{
			h=n-cnt%n+1;		
		}
	}
	cout<<l<<" "<<h;
	return 0;
} 
