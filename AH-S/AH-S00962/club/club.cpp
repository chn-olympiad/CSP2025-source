#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;

int t;
int n;
int answer;
int cnt[5];
int d[5][MAXN];
int a[5][MAXN];
int mx[MAXN];
int mi[MAXN];

inline int check_max(int x, int y, int z){
	if(x>=y && x>=z) return 1;
	if(y>=x && y>=z) return 2;
	return 3;
}

inline int check_mid(int x, int y, int z){
	if(x<=y && x<=z) return 1;
	if(y<=x && y<=z) return 2;
	return 3;
}

int main(){
	freopen("club.in","r",stdin);  	//zhuyi!!!
	freopen("club.out","w",stdout);
	
	scanf("%d" ,&t);
	while(t--){
		answer=0;
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		memset(mx,0,sizeof(mx));
		memset(mi,0,sizeof(mi));
		
		scanf("%d" ,&n);
		for(int i=1; i<=n; i++){
			scanf("%d%d%d" ,&a[1][i],&a[2][i],&a[3][i]);
			mx[i]=check_max(a[1][i],a[2][i],a[3][i]);
			mi[i]=6-mx[i]-check_mid(a[1][i],a[2][i],a[3][i]);
			if(mi[i]<1 || mi[i]>3) mi[i]=1;
			cnt[mx[i]]++;
			answer+=a[mx[i]][i];
			d[mx[i]][cnt[mx[i]]]=a[mx[i]][i]-a[mi[i]][i];
		}
		
		int flag=0;
		if(cnt[1]>n/2) flag=1;
		else if(cnt[2]>n/2) flag=2;
		else if(cnt[3]>n/2) flag=3;
		if(flag==0) {
			printf("%d\n" ,answer);
			continue;
		}
		
		sort(d[flag]+1,d[flag]+cnt[flag]+1);
		int di=cnt[flag]-n/2;
		for(int i=1; i<=di; i++) answer-=d[flag][i];
		printf("%d\n" ,answer);
	}
}
