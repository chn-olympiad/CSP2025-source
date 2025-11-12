#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int score, paiming;
int ansrow, anscol;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	score=a[1];
	sort(a+1, a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==score){
			paiming=n*m-i+1;
			break;
		}
	}
	if(paiming%n==0) anscol=paiming/n;
	else anscol=(paiming+n)/n;
	if(anscol%2==0) ansrow=n-paiming%n+1;
	else ansrow=paiming%n;
	if(ansrow==0) ansrow+=n;
	if(ansrow==n+1) ansrow-=n;
	cout<<anscol<<" "<<ansrow;
	
	
	return 0;
}
