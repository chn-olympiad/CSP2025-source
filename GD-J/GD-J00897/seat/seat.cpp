#include<bits/stdc++.h>
using namespace std;
const int maxs = 110;
array<int,2> a[maxs];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t = n * m;
	for(int i = 1;i <= t;i++){
		scanf("%d",&a[i][0]);
		a[i][1] = i;
	}
	sort(a+1,a+t+1,greater<>{});
	int l = 1,h = 1;
	for(int i = 1;i <= t;i++){
		if(a[i][1] == 1){
			printf("%d %d",l,h);
			return 0;
		}
		if(l & 1){
			++h;
			if(h > n)h = n,++l;
		}
		else{
			--h;
			if(!h)h = 1,++l;
		}
	}
}
