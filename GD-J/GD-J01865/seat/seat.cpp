#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int n,m,num,hang,lie;
int main(){
	//8:47-9:06 expect:100pts
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	if(num%n==0)lie=num/n;
	else lie=num/n+1;
	if(lie%2==1)hang=num-n*(lie-1);
	else hang=n+1-(num-n*(lie-1));
	cout<<lie<<" "<<hang;
	return 0;
}
