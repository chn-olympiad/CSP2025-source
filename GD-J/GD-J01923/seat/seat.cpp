#include<bits/stdc++.h>
using namespace std;
int n,m,a,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	s++;
	for(int i=2,c;i<=n*m;i++){
		cin>>c;
		if(c>a)s++;
	}
	int d=0,ans=0,ans_x=0,ans_y=0;
	for(int i=1;i<=n;i++){
		if(d==0){
			for(int j=1;j<=m;j++){
				ans++;
				if(ans==s){
					ans_x=i;
					ans_y=j;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				ans++;
				if(ans==s){
					ans_x=i;
					ans_y=j;
				}
			}
		}
		d^=1;
	}
	cout<<ans_x<<" "<<ans_y;
	return 0;
}
