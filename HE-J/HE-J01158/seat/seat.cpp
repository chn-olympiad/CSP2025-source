#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	bool ni=false;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			cout<<l<<" "<<h;
			return 0;
		}
		if(!ni)h++;
		if(ni)h--;
		if(h>n){
			l++;
			h=n;
			ni=true;
		}if(h<=0){
			l++;
			h=1;
			ni=false;
		}
		
	}
	
	return 0;
}
