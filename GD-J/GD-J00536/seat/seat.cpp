#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sc[15*15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++) cin>>sc[i];
	int x=sc[1];
	sort(sc+1,sc+n*m+1,cmp);
	int pl;
	for(int i=1;i<=n*m;i++) if(sc[i]==x){
		pl=i;
		break;
	}
	int res=(pl+n-1)/n;
	cout<<res<<' ';
	pl%=n;
	if(res%2==1){
		if(pl==0) cout<<n;
		else cout<<pl;
 	}
	else{
		if(pl==0) cout<<1;
		else cout<<n-pl+1;
	}
	return 0;
} 
/*
2 2
99 100 98 97
*/

/*
2 2
98 99 100 97
*/

/*
3 3
94 95 96 97 98 99 100 93 92
*/

/*
3 3
5 1 2 3 4 6 7 8 9
*/
