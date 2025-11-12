#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N+10],b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(b>n){
			b-=n;
		}
		else{
			if(i%2==1){
				cout<<i<<" "<<b;
				return 0;
			}
			else{
				cout<<i<<" "<<n-b+1;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

1 2

2 2
98 99 100 97

2 2

3 3
94 95 96 97 98 99 100 93 92

3 1

1 1
100

1 1

4 4
85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100

4 1
*/
