#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,ta,tap=0;
	cin>>n>>m;
	cin>>a[1];
	ta=a[1];
	int mn=n*m;
	for(int i=2;i<=mn;i++){
		cin>>a[i];
	}
	sort(a+1,a+mn+1,cmp);
	for(int i=1;i<=mn;i++){
		if(a[i]==ta){cout<<x<<" "<<y;
		return 0;	
		}
		else if(y!=n&&tap==0)y++;
		else if(y!=1&&tap==1)y--;
		else if(y==n){
			x++;
			tap=1;
		}
		else if(y==1){
			x++;
			tap=0;
		}
	}
return 0;
}
