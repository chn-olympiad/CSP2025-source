#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int t=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				t++;
				if(a[t]==x) return cout<<i<<" "<<j,0;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				t++;
				if(a[t]==x) return cout<<i<<" "<<j,0;
			}
		}
	}
	return 0;
}
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
//花斯卡，火斯卡，小花火！我前面的人在玩surf，考前就开始玩然后他写完题继续玩... 
