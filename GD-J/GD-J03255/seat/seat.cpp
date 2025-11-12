#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n,m;
int a[N];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n * m ;i++){
		scanf("%d",&a[i]);
	}
	int mark = a[1];
	sort(a + 1, a + n * m +1,cmp);
	int idx = 0;
	for(int i = 1;i<=n *m;i++){
		if(a[i] == mark){
			idx = i;
			break;
		}
	}
	int x = (idx + n - 1) / n;
	int y = idx % m == 0 ? m : idx % m;
	if(x % 2){
		printf("%d %d",x,y);
	}else{
		y = n - y + 1;
		printf("%d %d",x,y);
	}
	return 0;
}