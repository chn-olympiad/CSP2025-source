#include <bits/stdc++.h>
using namespace std;

int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int sa=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	for (int i=1;i<=n*m && c<=m;i++){
		if (a[i]==sa){
			printf("%d %d",c,r);
			break;
		}
		cout<<a[i]<<endl;
		if ((c%2==1 && r==n) || (c%2==0 && r==1)) c++;
		else if (c%2==1) r++;
		else r--;
	}
}
