
#include <bits/stdc++.h>
using namespace std;
int t;
long long ans=0;
struct node1 {
	int x,y,z,mx,mn,mi; //¥Û–°÷– 
}a[100005];
bool b(int n) {
	for(int i=1;i<=n;i++) {
		if(a[i].y!=0||a[i].z!=0) {
			return false;
		}                                                                                   
	}
	return true;
}
bool cmp(node1 s,node1 p) {
	return s.x>p.x;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		if(b(n)) {
			sort(a+1,a+n+1,cmp);
			cout << a[1].x+a[2].x << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
