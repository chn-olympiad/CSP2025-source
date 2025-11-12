#include<bits/stdc++.h>
using namespace std;
const int MAXN=15,MAXM=1e3+5;
int n,m;
int a[MAXM];
int id[MAXN][MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int pos=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			pos=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==pos){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==pos){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}