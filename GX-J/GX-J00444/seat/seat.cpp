#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,a[11000],x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int lyz=a[1],i=1;
	bool judge=1;
	sort(a+1,a+n*m+1,cmp);
	while(1){
		if(lyz==a[i]){
			cout<<x<<" "<<y;
			return 0;
		}
		i++;
		if(judge){
			if(y==n){
				x++;
				judge=0;
			}
			else{
				y++;
			}
		}
		else{
			if(y==1){
				x++;
				judge=1;
			}
			else{
				y--;
			}
		}
	}

}
