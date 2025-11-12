#include<bits/stdc++.h>
using namespace std;
int n,a[5005],u;
bool b[5005];
void hw(int cs,int ma,int zh){
	if(cs==n+1){
		if(ma*2<zh){
			u++;
			u%=998244353;
		}
		return;
	}
		hw(cs+1,ma,zh);
		hw(cs+1,max(ma,a[cs]),zh+a[cs]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	hw(1,0,0);
	cout<<u;
	return 0;
}
