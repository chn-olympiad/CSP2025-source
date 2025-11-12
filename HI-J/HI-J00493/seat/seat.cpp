#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,l,s,x,y;
int a[102];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==s)l = i;
	x = (l-1)/n+1;
	if(x%2==1){
		y = (l-1)%n+1;
	}else{
		y = n+1-((l-1)%n+1);
	}
	cout<<x<<" "<<y;
	return 0;
}


