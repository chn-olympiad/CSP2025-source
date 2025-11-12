#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m,t,x,y,h=1;
int a[N];
bool cmp(int s1,int s2)
{
	return s1>s2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			x=1,y=i;
			for(;x<=n;x++){
				if(a[h]==t){
					cout<<y<<" "<<x;
					return 0;
				}
				h++;
			}
		}
		else{
			x=n,y=i;
			for(;x>=1;x--){
				if(a[h]==t){
					cout<<y<<" "<<x;
					return 0;
				}
				h++;
			}
		}
	}
	return 0;
}
