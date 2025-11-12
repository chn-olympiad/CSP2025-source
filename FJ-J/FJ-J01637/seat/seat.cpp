#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nem[120];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>nem[i];
	int manr=nem[1];
	sort(nem+1,nem+n*m+1,greater<int>());
	int r;
	for(int i=1;i<=n*m;i++){
		if(nem[i]==manr) r=i;
	}
	if(((r-1)/m+1)%2==1) cout<<(r-1)/m+1<<" "<<(r-1)%m+1;
	else cout<<(r-1)/m+1<<" "<<n-(r-1)%m;
	return 0; 
} 
