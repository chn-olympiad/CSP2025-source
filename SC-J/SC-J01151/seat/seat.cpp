#include<bits/stdc++.h>
#define N 105
#define LL long long
//#define int long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

int n,m,cnt,a[N],x,y,num;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt];
		}
	}
	num=a[1];
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(i%n==1){
			x++;
			if(x&1) y=0;
			else y=n+1;
		}
		if(x&1) y++;
		else y--;
		if(a[i]==num){
			cout<<x<<" "<<y;
			return 0;
		}
	}
//	printf("\ntime:%.0lfms",(double)clock());
	return 0;
}//知颖你太美