#include<bits/stdc++.h>
using namespace std;
int n,mm,cj[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>mm;
	for(int i=0;i<n*mm;i++) cin>>cj[i];
	int R=cj[0],x;
	sort(cj,cj+n*mm);
	for(int i=0;cj[i]!=R;i++) x=n*mm-i-2;
//	cout<<x<<'\n';
	cout<<x/mm+1<<' ';
	if((x/mm+1)%2) cout<<(x%mm+1);
	else cout<<(mm-x%mm);
	return 0;
}
