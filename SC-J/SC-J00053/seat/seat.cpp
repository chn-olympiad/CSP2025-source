#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int need;
	for(int i=1;i<=n*m;i++){
		int tmp;
		cin>>tmp;
		if(i==1)
			need=tmp;
		a[i]=tmp;
	}
	
	sort(a+1,a+1+n*m,cmp);
	int rnk;
	for(int i=1;i<=n*m;i++)
		if(a[i]==need){
			rnk=i;
			break;
		}

	int cnt=0;
	for(int i=1;i<=n;i++)
		if(i&1)
			for(int j=1;j<=m;j++){
				cnt++;
				if(cnt==rnk){
					cout<<i<<' '<<j;
					break;
				}
			}
		else
			for(int j=m;j>=1;j--){
				cnt++;
				if(cnt==rnk){
					cout<<i<<' '<<j;
					break;
				}
			}
	return 0;
}