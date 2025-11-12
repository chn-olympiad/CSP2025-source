#include<bits/stdc++.h>
using namespace std;

bool cmd(int a,int b){return a>b;}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,a[111],l=0;
	cin>>n>>m>>R,a[0]=R;
	for(int i=1;i<n*m;++i)cin>>a[i];
	sort(a,a+n*m,cmd);
	for(;;l++)if(a[l]==R)break;
	//for(int i=0;i<n*m;++i)cout<<a[i];
	cout<<l/n+1<<" "<<((l/n)%2==0?(l%n+1):(m-l%n));
}
