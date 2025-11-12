#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m;
int a[N];
int b[N][N];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	int b=1;
	for(int i=1; i<=n*m; i++){
		if(a1==a[i]){
			cout<<x<<" "<<y;
			break;
		}
		if(y==m&&b==1){
			b=2;
			x++;
			continue;
		}else if(y==1&&b==2){
			b=1; x++;
			continue;
		}
		if(b==1){
			y++;
		}else if(b==2){
			y--;
		}
	}
	return 0;
}
