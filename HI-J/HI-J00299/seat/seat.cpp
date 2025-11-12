#include<bits/stdc++.h>
using namespace std;
int sc,n,m,cnt=1,R;//littleR
void solve(){
	int l=1,h;//lie,hang
	l+=(cnt/(2*n)*2);
	cnt%=(2*n);
	if(cnt==0) cout<<(l-1)<<" 1\n";
	else if(cnt<=n) cout<<l<<" "<<cnt<<"\n";
	
	else{
		cout<<l<<" "<<(2*n+1-cnt)<<"\n";
	}
}
int main(){//int2 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	
	for(int i=2;i<=n*m;i++){
		cin>>sc;
		if(sc>R)cnt++;
	}
	solve();
	return 0;
	fclose(stdin);
	fclose(stdout);
}/*3 3
94 95 96 97 98 99 100 93 92*/
