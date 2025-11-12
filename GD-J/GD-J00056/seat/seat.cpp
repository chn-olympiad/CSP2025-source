#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
int n,m,a[114514/100],littleR,threepoint;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;for(int i=0;i<n*m;i++) cin>>a[i];
	littleR=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++) if(a[i]==littleR) threepoint=n*m-i;
	cout<<threepoint/n+1<<' '<<((threepoint/n+1)%2 ? threepoint-threepoint/n*n:n+1-threepoint+threepoint/n*n);
	return 0;
}//#Shang4Shan3Ruo6Shui4
