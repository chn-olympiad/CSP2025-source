#include<bits/stdc++.h>
using namespace std;
int n, k, h, ans, t, maxn, a[500005];
struct node{
	int x, y;
}f[1000005];
bool cmp(node xx, node yy){
	return xx.y<yy.y || xx.y==yy.y && xx.x>yy.x;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	if(maxn==1){
		int sum=0;
		if(k==1){
			for(int i=1; i<=n; i++){
				if(a[i]==1) sum++;
			}
		}else{
			for(int i=1; i<=n; i++){
				if(a[i]==0) sum++;
				else{
					if(a[i]==1 && a[i+1]==1){
						sum++;
						i++;
					}
				}
			}
		}
		printf("%d", sum);
		return 0;
	}
	for(int i=1; i<=n; i++){
		int g=a[i];
		if(g==k){
			h++;
			f[h].x=f[h].y=i;
		}
		for(int j=i+1; j<=n; j++){
			g^=a[j];
			if(g==k){
				h++;
				f[h].x=i;
				f[h].y=j;
			}
		}
	}
	sort(f+1, f+1+h, cmp);
	for(int i=1; i<=h; i++){
		if(f[i].x>t){
			ans++;
			t=f[i].y;
		}
	}
	printf("%d", ans);
	return 0;
}

