#include<bits/stdc++.h>
using namespace std;
long long int s[110],n,m,x,y,h;
bool k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	h=s[1];
	x=1;
	y=1;
	sort(s+1,s+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(s[i]==h){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&k==0){
			y++;
			k=1;
			continue;
		}
		if(x==1&&k==1){
			y++;
			k=0;
			continue;
		}
		if(k==0){
			x++;
		}else{
			x--;
		}
	}
	return 0;
}
