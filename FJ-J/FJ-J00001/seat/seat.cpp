#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[1000005];
int r;
int cmp(int a,int b){
	return a>b; 
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+(n*m)+1,cmp);
	int cnt;
	for(int i=1;i<=n*m;i++){
		if(b[i]==r){
			cnt=i;
			break;
		}
	}
	int ansm;
	int ansn;
	ansm=cnt/n;
	if((ansm*n)<cnt) ansm++;
	ansn=cnt%(2*n);
	int anssum=1+2*n;
	if(ansn>n) ansn=anssum-ansn;
	else if(ansn==0) ansn=n;
	cout<<ansm<<' '<<ansn;
	return 0;
}
