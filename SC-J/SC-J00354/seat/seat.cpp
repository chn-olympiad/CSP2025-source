#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
int s[105][105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){//列 
		if(i%2==0){
			for(int j=n;j>=1;j--){//行 
				if(a[k]==f){
					cout<<i<<" "<<j;
					return 0;
				}
				s[j][i]=a[k++];
			}
		} else{
			for(int j=1;j<=n;j++){
				if(a[k]==f){
					cout<<i<<" "<<j;
					return 0;
				}
				s[j][i]=a[k++];
			} 
		}
	}
	return 0;
 }

