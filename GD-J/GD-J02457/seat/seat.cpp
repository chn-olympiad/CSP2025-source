#include<algorithm>
#include<iostream>
using namespace std;
const int N=105;
int n,m,xb;
pair<int,int> a[N];
bool cmp(pair<int,int> x,pair<int,int> y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				xb++;
				if(a[xb].second==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				xb++;
				if(a[xb].second==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
