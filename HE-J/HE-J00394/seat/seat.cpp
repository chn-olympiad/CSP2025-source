#include<bits/stdc++.h>
using namespace std;

int s[12][12];
int w[12*12];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&w[i]);
	}
	int R=w[1];
	sort(w+1,w+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++){
				s[j][i] = w[cnt];
				if(w[cnt]==R){
					cout << i << ' ' << j;
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--){
				s[j][i] = w[cnt];
				if(w[cnt]==R){
					cout << i << ' ' << j;
					return 0;
				}
				cnt++;
			}
		}
	}

	return 0;

}
