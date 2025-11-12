#include <bits/stdc++.h>
using namespace std;
int s[107];
int n,m,x,y,k=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++) cin>>s[i];
	sort(s+1,s+n*m,cmp);
	while (s[0]<s[k]){
		k++;
	}
	int x=(k-1)/n+1;
	if (x%2)
		y=(k-1)%n+1;
	else
		y=n*x-k+1;
	cout<<x<<' '<<y;
	return 0;
}
