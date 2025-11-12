#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m,a,t=1;
	scanf("%d%d%d",&n,&m,&a);
	
	for(int i=2,len=n*m;i<=len;i++) {
		int temp;
		scanf("%d",&temp);
		if(temp>a) t++;
	}
	
	int c=1;
	
	while(t>0) {
		if(t<=n) {
			if(c%2) {
				printf("%d %d",c,t);
			} else {
				printf("%d %d",c,n-t+1);
			}
		}
		t -= n;
		c++;
	}
	
	return 0;
}
