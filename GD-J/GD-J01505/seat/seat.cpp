#include<bits/stdc++.h>
using namespace std;
int cnt,cnt2;
bool cmp(int a,int b){
	return a>b;
}
int a[1005];
struct people{
	int x;
	int y;
};
people ans[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
		if(i == 1) cnt2 = a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<= m;i++){
		for(int j = 1;j<=n;j++){
			ans[++cnt].x = i;
			ans[cnt].y = j;
		}
		
		i++;
		if(i<=m){
			for(int j = n;j>=1;j--){
				ans[++cnt].x = i;
				ans[cnt].y = j;
			}
		}
	}
	for(int i = 1;i<=n*m;i++){
		if(cnt2 == a[i]){
			cout<<ans[i].x <<" "<<ans[i].y ;
			break;
		}
	}
	return 0;
} 
