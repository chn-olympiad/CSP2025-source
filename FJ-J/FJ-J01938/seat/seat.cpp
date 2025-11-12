#include <bits/stdc++.h>
using namespace std;
int a[1010],n,m;
int main()
{
	freopen("seat.in","r",FILE);
	freopen("seat.out","w",FILE);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	int cnt;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cnt=i;
			break;
		}
	}
	cnt=n*m-cnt+1;
	int ansq=(cnt-1)%n+1;
	int answ=(cnt-1)/n+1;
	if(answ%2==0){
		ansq=n-ansq+1;
	}
	cout<<answ<<" "<<ansq;
	return 0;
}
