#include <bits/stdc++.h>
using namespace std;
int n,m,score[105],loc,s,ans1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>score[i];
		if(i==0) s=score[i];
	}
	sort(score,score+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(score[i]==s) loc=i+1;
	}
	if(loc%n!=0) ans1=int(loc/n)+1;
	else ans1=loc/n;
	cout<<ans1<<" ";
	if(ans1%2) cout<<loc%n;
	else cout<<n-(loc%n)+1;
	return 0;
}
