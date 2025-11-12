#include<iostream> 
#include<algorithm>
using namespace std;
int n,m,a[105]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int R=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int flag=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(flag==0){ 
			for(int j=1;j<=n;j++){
				if(a[++cnt]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			flag=1;
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++cnt]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			flag=0;
		}
	}
	return 0;
}