#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],score,ans,x,y,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(i==1) score=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			ans=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(cnt==ans){
				cout << i << ' ' << j;
				break;
			}
		}
		i++;
		if(i>m) break;
		for(int j=n;j>=1;j--){
			cnt++;
			if(cnt==ans){
				cout << i << ' ' << j;
				break;
			}
		}
	}
	return 0;
}
