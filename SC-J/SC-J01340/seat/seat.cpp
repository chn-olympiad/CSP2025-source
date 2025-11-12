#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	a[0]=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int idx=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a[0]){
			idx=i;
			break;
		}
	}
	int range=(idx-1)/n+1,row=(idx-1)%n+1;
	if(range%2==0)row=n-row+1;
	printf("%d %d",range,row);
	return 0;
}