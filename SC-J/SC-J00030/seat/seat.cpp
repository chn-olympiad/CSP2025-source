#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],b,k;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	b=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==b){
			k=i;
			break;
		}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}