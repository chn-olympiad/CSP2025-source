#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[15][15];
struct stu{
	int xx;
	int flag=0;
}b[115];
bool cmp(stu x,stu y){
	return x.xx>y.xx;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i].xx;
	int kg=b[1].xx;
	sort(b+1,b+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[j][i]=b[k].xx;
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==kg){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
