#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,m,a[1010],score,cnt;
bool flag;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+n*m+1,cmp);
	flag=false;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt]==score){
					cout<<i<<' '<<j;
					flag=true;
					break;
				}
			}
		}
		else {
			for(int j=n;j>=1;j--){
				if(a[++cnt]==score){
					cout<<i<<' '<<j;
					flag=true;
					break;
				}
			}
		}
		if(flag)break;
	}
//	system("fc seat.out seat1.ans");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
