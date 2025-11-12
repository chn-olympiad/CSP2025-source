#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ri,ai;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ai;
	a[1]=ai;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ai)ri=i;
	}
	int i=1,x=1,y=1;
	string f="dz";
	while(i<=ri){
		if(i==ri){
			cout<<x<<" "<<y;
			return 0;
		}
		if(f=="dz"){
			if(y<n){
				y++;
			}else{
				f="dj";
				x++;
			}
		}else{
			if(y>1){
				y--;
			}else{
				f="dz";
				x++;
			}
		}
		i++;
	}
	return 0;
} 
