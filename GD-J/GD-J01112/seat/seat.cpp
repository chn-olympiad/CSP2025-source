#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=15,K=15*15;
int n,m,k,s,a[K],st[N][N];
/*
n 为行
m 为列 
k=n*m
s 为 小 R 的分数 
*/
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+k+1,cmp);
	int x=1,y=1,ind=1;
	while(a[ind]!=s){
		if(y%2==1){
			if(x==n)y++;
			else x++;
		}else{
			if(x==1)y++;
			else x--;
		}
		ind++;
	}
	cout<<y<<' '<<x<<'\n';
	return 0;
}
/*
note:
模拟
*/

