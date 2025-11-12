//04 
#include<iostream>
#include<algorithm>
using namespace std;

long long n,m,k,cnt,ans;
struct Edge{
	long long s,t,l;
	int belong;
}a[100005];
long long c[15];
int f[10015];

void init(){
	for (int i = 1;i <= n + k;i++){
		f[i] = i;
	} 
}

long long finddad(long long son){
	if (f[son] == son){
		return son;
	}else{
		f[son] = finddad(f[son]);
		return f[son];
	}
}

void merge(long long x,long long y){
	long long fa = finddad(x);
	long long fb = finddad(y);
	if (fa != fb){
		f[fb] = fa;
	}
}

bool cmp(Edge x,Edge y){
	return x.l + c[x.belong] < y.l + c[y.belong];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (long long i = 1;i <= m;i++){
		cnt++;
		cin >> a[cnt].s >> a[cnt].t >> a[cnt].l;
		a[cnt].belong = 0;
	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++){
			cnt++;
			a[cnt].s = i + n;
			a[cnt].t = j;
			cin >> a[cnt].l;
			a[cnt].belong = i;
		}
	}
	init();
	sort(a+1,a+cnt+1,cmp);
	for (int i = 1;i <= cnt;i++){
		bool flag = true;
		for (int j = 1;j <= n;j++){
			if (finddad(j) != finddad(1)){
				flag = false;
				break;
			}
		}
		if (flag) break;
		flag = false;
		if (finddad(a[i].s) != finddad(a[i].t)){
 			merge(a[i].s,a[i].t);
			ans += a[i].l + c[a[i].belong];
			c[a[i].belong] = 0;
			flag = true;
		}
	}
	cout << ans;
	return 0;
}

//30 
