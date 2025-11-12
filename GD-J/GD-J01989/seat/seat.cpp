#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,m;
int mp[MAXN]; 
int wei;
int pai;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>mp[i];
	}
	wei=mp[1];
	sort(mp+1,mp+n*m+1);
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(mp[i]==wei){
			pai=j;
			break;
		} 
	}
	if(pai%m==0){
		if((pai/m)%2==1){
			x=pai/m;
			y=n; 
		}
		else{
			x=pai/m;
			y=1;
		}
	}
	else{
		if((pai/m+1)%2==1){
			x=pai/m+1;
			y=pai%m;
		}
		else{
			x=pai/m+1;
			y=n-pai%m+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
