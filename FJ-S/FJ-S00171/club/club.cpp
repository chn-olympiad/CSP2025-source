#include<bits/stdc++.h>
#include<vector>
#include<cstdlib>

using namespace std;

int n;
int a[100005][5] = {0};	//原始数据 
vector<int> p[5];	//忽略条件的理想化方案 
int lost[100005] = {0};	//如果必须调动走员工，则会损失多少期望值 
int ans = 0;	//总期望值 
int pot[30000] = {0};

#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))

inline int fastread() {
	int rst = 0;
	char ch = getchar();
	while(ch!=EOF && !isdigit(ch)) ch = getchar();
	while(ch!=EOF && isdigit(ch)) {
		rst *= 10;
		rst += ch-'0';
		ch = getchar();
	}
	return rst;
}

inline void init(int x) {
	//初始化第x个员工数据 
	int mx = max3(a[x][1],a[x][2],a[x][3]);
	int mn = min3(a[x][1],a[x][2],a[x][3]);
	int i=1;
	while(mx!=a[x][i]) i++;
	p[i].push_back(x);
	ans += mx;
	lost[x] = (a[x][1]+a[x][2]+a[x][3]-mx-mn)-mx;
}

inline void potsort(int x) {
	vector<int>& q = p[x];
	memset(pot,0,sizeof(pot));
	for(int i=0,len=q.size();i<len;i++) {
		pot[-lost[q[i]]]++;
	}
}

void judge() {
	
	// init is all i need.
	p[1] = p[2] = p[3] = vector<int>();
	ans = 0;
	
	int n;
	n = fastread();
	//scanf("%d",&n);
	
	for(int i=1;i<=n;i++) {
		a[i][1] = fastread();
		a[i][2] = fastread();
		a[i][3] = fastread();
		//scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		init(i);
	}
	
	for(int i=1;i<=3;i++) {
		int sz = p[i].size();
		if(sz>n/2) potsort(i);
		int hope = 0;
		while(sz>n/2) {
			//触发调节 
			while(pot[hope]==0) hope++;
			ans -= hope;
			pot[hope]--;
			sz--;
		}
	}

	printf("%d\n",ans);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	T = fastread();
	//scanf("%d",&T);
	
	while(T--) {
		judge();
	}
	
	return 0;
}

/*
DEBUG p and lost
//	printf("init p:\n");
//	for(int i=1;i<=3;i++) {
//		for(unsigned int j=0;j<p[i].size();j++) {
//			printf("%d ",p[i][j]);
//		}
//		printf("\n");
//	}
//	printf("init lost:\n");
//	for(int i=1;i<=n;i++) {
//		printf("%d ",lost[i]);
//	}
//	printf("\n");
DEBUG pot
//	for(int i=0,len=q.size();i<len;i++) {
//		printf("pot: q[i]=%d,lost[q[i]]=%d,pot[-lost[q[i]]]=%d\n",q[i],lost[q[i]],pot[-lost[q[i]]]);
//	}
*/
