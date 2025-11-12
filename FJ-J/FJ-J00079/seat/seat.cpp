#include<bits/stdc++.h>
#define MAXN 114
using namespace std;
int arr[MAXN];
int n,m;
bool cmp(int a,int b) {
	return a>b;
}
int mp[MAXN][MAXN];
int R;
int fj(int a) {
	if (a==1) return -1;
	if (a==-1) return 1;
}
void out() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>arr[i];
	R=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	int col=1,state=1,row=1,cnt=0;
	for(int i=1;i<=n*m;i++) {
		
		
		//cout<<row<<" "<<col<<endl;
		mp[row][col]=arr[i];
		if (arr[i]==R) {
			cout<<col<<" "<<row<<endl;
			return 0;
		}
		row+=state;
		cnt++;
		if (cnt>=n) {
			cnt=0;
			state=fj(state);
			col++;
			row+=state;
		}
		
	}
	//out();
}
/*
2 6
10 77 54 34 22 21 99 5 4 3 2 1

*/
