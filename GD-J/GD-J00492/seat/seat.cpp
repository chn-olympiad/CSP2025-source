#include<iostream>
#include<algorithm>
using namespace std;
int n,m,mp[20][20],cnt=1,a[200],k,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[i][j]=cnt;
				cnt++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				mp[i][j]=cnt;
				cnt++;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	int l=n*m;
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==k){
			t=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==t){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
