#include<bits/stdc++.h>
using namespace std;
int l1,l2,b,n,m,t,a[105];
int cmp(int x,int y){
	return x>y;
	}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i]==b) t=i;
	for(int i=1;i<=m;i++){
		if(n*i>=t){
			l1=i;
			t=t-n*(i-1);
			break;
			}
		}
	if(l1%2==0){
		l2=n+1-t;
		cout<<l1<<" "<<l2;
		}
	else cout<<l1<<" "<<t;
return 0;
}
