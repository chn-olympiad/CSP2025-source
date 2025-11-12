#include<bits/stdc++.h>
using namespace std;

int seat[15][15];
int a[105];
bool cmp(int x,int y){
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cur=1,t;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[cur++];
			if(i==1 && j==1) t=a[cur-1];
		}
	}
	sort(a+1,a+cur+1,cmp);
	int q;
	for(int i=1;i<=cur;i++) if(a[i]==t) q=i;
	int w=q/n,e=q%n;
	if(e==0) cout <<  w << ' ' << n << endl;
	else if(w%2==0) cout << w+1 << ' ' << e << endl;
	else cout << w+1 << ' ' << n-e+1 << endl;
	return 0;
}
