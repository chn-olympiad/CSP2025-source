#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			k=i;
			break;
		}
	}
	int j=1;
	while(1){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				cnt++;
				if(cnt==k){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				cnt++;
				if(cnt==k){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		j++;
	}
	return 0;
}
