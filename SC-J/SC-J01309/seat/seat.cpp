#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,len,loc,score,data[N*N];
int l,r,num[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++) cin>>data[i];
	score=data[1];
	stable_sort(data+1,data+len+1);
	reverse(data+1,data+len+1);
	for(int i=1;i<=len;i++){
		if(score==data[i]){
			loc=i;
			break;
		}
	}
	l=(loc+m-1)/m;
	r=loc-(l-1)*m;
	if(l%2==0) r=m-r+1;
	cout<<l<<" "<<r;
	return 0;
}
/*

2 2
99 100 97 98

1 2

2 2
98 99 100 97

2 2
*/