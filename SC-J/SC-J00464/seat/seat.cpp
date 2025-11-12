#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a,b=1,sco[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//给定小R所在的考场座位的行数 n 与列数 m，
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++)
		cin>>sco[i];
	sort(sco+1,sco+n*m,greater<int>());
	for(int i=2;i<n*m;i++)
		if(sco[i-1]>a&&sco[i]<a){
			b=i;
			break;
		}
	if(((b-1)/n)&1)cout<<((b-1)/n+1)<<" "<<(n+1-(b%n));
	else cout<<((b-1)/n+1)<<" "<<((b-1)%n+1);
	//第几列第几行,可以的
	return 0;
}