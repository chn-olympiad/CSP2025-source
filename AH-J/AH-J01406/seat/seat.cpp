#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int sum=a[1],ans=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) 
		if(a[i]==sum) ans=i;
	int course=ans/n,settr=ans%n;
	if(settr==0) cout<<course<<" "<<(course%2==1?n:1);
	else cout<<course+1<<" "<<(course%2==1?n-settr+1:settr);
	return 0;
}
