#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for (int i=1;i<=k;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+k+1);
	for (int i=k;i>=1;i--){
		cnt++;
		if (a[i]==t)break;
	}
	int am=cnt/n;
	if (cnt%n!=0)am+=1;
	int an=0,v=cnt%n;
	if (v==0)v=m;
	if (am%2==1)an=v;
	else an=n-v+1;
	cout<<am<<" "<<an;
	return 0;
}