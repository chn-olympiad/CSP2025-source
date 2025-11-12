#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,mark;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	mark=a[1]; sort(a+1,a+n*m+1);
	int mc=n*m-(lower_bound(a+1,a+n*m+1,mark)-a)+1,xxx,yyy;
	if(mc%m==0){
		xxx=mc/m; 
		if(xxx%2==1) yyy=1;
		else yyy=n;
	}
	else{
		xxx=mc/m+1;
		if(xxx%2==1) yyy=mc%n;
		else yyy=n-mc%n+1;
	}
	cout<<xxx<<" "<<yyy;
	return 0;
}