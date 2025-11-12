#include<bits/stdc++.h>
using namespace std;
const int MAXMN=10;
int n,m,o,r,ans,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>r;
	ans++;
	for(int i=1;i<n*m;i++){
		cin>>o;
		if(o>r){
			ans++;
		}
	}
	x=(ans-1)/n+1;
	y=((x%2==0)?(n+1-(ans-n*(x-1))):((ans-n*(x-1))));
	cout<<x<<' '<<y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
