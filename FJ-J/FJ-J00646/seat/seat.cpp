#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],flag,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	flag=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==flag){
			flag=i;
			break;
		}
	c=flag/n;
	if(flag%n!=0) c++;
	if(c%2==1) r=(flag-1)%n+1;
	else r=n-(flag-1)%n;
	cout<<c<<" "<<r;
	return 0;
} 

