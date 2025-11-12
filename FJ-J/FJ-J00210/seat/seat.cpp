#include<iostream>

using namespace std;

int a[1005];
short s[15][15];
int ans=0;
int see=0;
int momest(int x,int y)
{
	for(;a[ans] == 0;ans--){}
	s[x][y] = ans;
//	cout<<ans<<" ";
	a[ans] = 0;
	if(ans == see) {
		return true;
	}
	ans--;
	return false;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int w;
		cin>>w;
		if(i==1) see = w;
		a[w] ++;
	}
	ans=101;
	for(int j=1;j<=m;j++)
	{
		int i=0;
		if(j%2==1){
			for(int i=1;i<=n;i++) {
				if(momest(j,i)){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else {
			for(int i=n;i>=1;i--) {
				if(momest(j,i)){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	cout<<"Inportant.Error";
	return 0;
}
