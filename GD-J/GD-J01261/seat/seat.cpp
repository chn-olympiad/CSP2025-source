#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,seat[10005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cinNum=n*m;
	for(int i=1;i<=cinNum;i++)cin>>seat[i];
	int R=seat[1],where;
	sort(seat+1,seat+cinNum+1,cmp);
	for(int i=cinNum+1;i>=1;i--){
		if(seat[i]==R){
			where=i;
			break;
		}
	}
	int hang,lie;
	if(where%n==0){
		lie=where/n;
		if(lie%2==1){
			hang=m;
			cout<<lie<<" "<<hang;
			return 0;	
		}
		else{
			hang=1;
			cout<<lie<<" "<<hang;
			return 0;
		}
	}
	else lie=where/n+1;
	if(lie%2==1)hang=where%n;
	else hang=m-(where%n)+1;
	cout<<lie<<" "<<hang;
	return 0;
} 
