#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	//for(int i=1;i<=n*m;i++)cout<<a[i];
	//cout<<endl;
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i];
	//cout<<endl;
	int idx=0;
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<endl;
		if(a[i]==s){
			idx=i;
			break;
		}
	}
	int c=(idx-1)/n+1,row=idx%n;
	//cout<<idx<<' '<<c<<' '<<row<<endl;
	if(row==0)row=n;
	if(c%2==1)r=row;
	else r=n-row+1;
	cout<<c<<' '<<r;
	return 0;
}
