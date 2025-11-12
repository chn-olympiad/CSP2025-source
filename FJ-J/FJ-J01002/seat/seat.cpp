#include <bits/stdc++.h>
using namespace std;
int a[1000][10000],n,m,mark,p[1000000],cnt=1,ansn,ansm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>p[i];
	}
	mark=p[1];
	sort(p+1,p+1+m*n);
	for(int i=m*n;i>=1;i--){
		if(p[i]==mark){
			break;
		}
		cnt++;
	}
	ansm=cnt/n;
	if (cnt%n!=0){
		ansm++;
	}
	if ((cnt/n)%2==0){
		ansn=cnt%n;
	}
	else{
		ansn=n-(cnt%n);
	}
	cout<<ansm<<' '<<ansn;
	return 0;
}
