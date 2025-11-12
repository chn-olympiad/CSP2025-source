#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
using ll=long long;
int n,m,x,y,res;
int a[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+1+n*m);
	bool flag=0;
	for(int i=1;i<=n*m;i++){
		if(x==a[i])y=n*m-i+1;
	}
	res=(y-1)/m+1;
	cout<<res<<" ";
	y=y-(res-1)*n;
//	cout<<y<<endl;
	if(res%2!=0){//1->n
		cout<<y<<endl;
	}else{//n->1
		cout<<n-y+1<<endl;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98
2 2
98 99 100 97
*/
