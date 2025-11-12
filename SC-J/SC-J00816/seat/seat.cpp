#include<bits/stdc++.h>
using namespace std;

int n,m,a[101];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	bool ok=false;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cout<<c<<" "<<r;
		}if((!ok&&r==n)||(ok&&r==1)){
			c++;
			ok=!ok;
		}else if(!ok){
			r++;
		}else if(ok){
			r--;
		}
	}
	return 0;
} 