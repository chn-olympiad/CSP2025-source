#include<bits/stdc++.h>
using namespace std;

int sc[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,cnt=0;
	cin >> n >> m >> R;
	sc[1] = R;
	for(int i=2;i<=n*m;i++){
		cin >> sc[i];
	}
	sort(sc+1,sc+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(sc[cnt] == R){
					cout << i << ' ' << j;
					break;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(sc[cnt] == R){
					cout << i << ' ' << j;
					break;
				}
			}
		}
	}
	return 0;
}
