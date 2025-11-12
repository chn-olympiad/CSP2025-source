#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a,tmp,num;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	num = 1;
	for(int i = 2;i<=n*m;i++){
		cin>>tmp;
		if(tmp>a)num++;
	}
//	cout<<num<<'\n';
	y = (num/n+(num%n!=0));//ÁÐÊý 
	if(y%2)x = num%n;
	else x = n-(num%n==0?n:num%n)+1;
	if(x==0)x = n;
	cout<<y<<" "<<x;
}
