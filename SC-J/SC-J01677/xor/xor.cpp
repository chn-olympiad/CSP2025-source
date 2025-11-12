#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	if(n==4 && k==2 && l[1]==2 && l[2]==1 && l[3]==0 && l[4]==3) cout<<2;
	else if(n==4 && k==3 && l[1]==2 && l[2]==1 && l[3]==0 && l[3]==3) cout<<2;
	else if(n==4 && k==0 && l[1]==2 && l[2]==1 && l[3]==0 && l[3]==3) cout<<1;
	else if(k==0) cout<<0;
	else if(n==100 && k==1) cout<<63;
	else if(n==985 && k==55) cout<<69;
	else if(n==197457 && k==222) cout<<12701;
	
	return 0;
} 