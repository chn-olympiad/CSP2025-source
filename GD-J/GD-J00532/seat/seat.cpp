#include<bits/stdc++.h>
using namespace std;
int sc[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R_sc;
	cin>>R_sc;
	int vv=(n*m)-1;
	for(int i=1;i<=vv;i++){
		cin>>sc[i];
	}
	sort(sc+1,sc+vv+1);
	int cnt=1;
	for(int i=vv;i>=1;i--){
		if(sc[i]<R_sc){
			break;
		}
		cnt++;
	}
	int x=cnt/n;
	if(cnt%n!=0)x++;

	cout<<x<<' ';//
	
	if(cnt%n!=0)cnt%=n;
	if(cnt%n==0)cnt=n;
	int xs=x%2;
	
	if(xs==0)cout<<n-cnt+1;
	else {
		cout<<cnt;//
	}
	return 0;
}
