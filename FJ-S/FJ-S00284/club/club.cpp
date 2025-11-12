#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

void read(int &x){
	x=0;
	char ch=getchar();
	while (!isdigit(ch))	ch=getchar();
	while (isdigit(ch)){
		x*=10;
		x+=ch-48;
		ch=getchar();
	}
}

int a[100009][4];
int vis[100009], cnt[4];
int num[100009], tot;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=3; j++)
				read(a[i][j]);
		
		int ans=0;
		for (int i=1; i<=n; i++){ // 贪心 
			if (a[i][1]>a[i][2] && a[i][1]>a[i][3]){
				cnt[1]++;
				vis[i]=1;
				ans+=a[i][1];
			}
			else if (a[i][2]>a[i][3]){
				cnt[2]++;
				vis[i]=2;
				ans+=a[i][2];
			}
			else{
				cnt[3]++;
				vis[i]=3;
				ans+=a[i][3];
			}
		}
		
		if (cnt[1]>n/2){ // 调整(任意) 
			for (int i=1; i<=n; i++)
				if (vis[i]==1)
					num[++tot]=max(a[i][2]-a[i][1], a[i][3]-a[i][1]);
			sort(num+1, num+tot+1);
			for (int i=n/2+1; i<=tot; i++)	ans+=num[i];
		}
		if (cnt[2]>n/2){ // Ctrl+C
			for (int i=1; i<=n; i++)
				if (vis[i]==2)
					num[++tot]=max(a[i][1]-a[i][2], a[i][3]-a[i][2]);
			sort(num+1, num+tot+1);
			for (int i=n/2+1; i<=tot; i++)	ans+=num[i];
		}
		if (cnt[3]>n/2){ // Ctrl+V
			for (int i=1; i<=n; i++)
				if (vis[i]==3)
					num[++tot]=max(a[i][1]-a[i][3], a[i][2]-a[i][3]);
			sort(num+1, num+tot+1);
			for (int i=n/2+1; i<=tot; i++)	ans+=num[i];
		}
		
		printf("%d\n", ans);
		
		cnt[1]=cnt[2]=cnt[3]=0;
		tot=0;
	}
	return 0;
}
