#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e6;
int t,n,sum,tmp,cnt = -inf;
struct cy{
	int a1,a2,a3,mx,w;
}a[N];
int c[6],vis[N];
bool cmp1(cy x,cy y){
	return x.a1 > y.a1;	
}
bool cmp2(cy x,cy y){
	return x.a2 > y.a2;	
}
bool cmp3(cy x,cy y){
	return x.a3 > y.a3;	
}
void d1(){

	for(int i = 0;i < n;i++){
			if(c[1] < n / 2 && !vis[i]){
				c[1]++;
				vis[i] = 1;
				sum += a[i].a1;
			}
		}
}
void d2(){

	for(int i = 0;i < n;i++){
			if(c[2] < n / 2 && !vis[i]){
				c[2]++;
				vis[i] = 1;
				sum += a[i].a2;
			}
		}
}
void d3(){

	for(int i = 0;i < n;i++){
			if(c[3] < n / 2 && !vis[i]){
				c[3]++;
				vis[3] = 1;
				sum += a[i].a3;
			}
		}
}
signed main(){
  	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		for(int i = 0;i < n;i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].mx = max(max(a[i].a1,a[i].a2),a[i].a3);
			a[i].w = i;
			
		}
		cnt = -inf;
		sum = 0;
		sort(a,a + n,cmp1);
		d1();
		sort(a,a + n,cmp2);
		d2();
		sort(a,a + n,cmp3);
		d3();
		cnt = max(cnt,sum);
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));//1
		
		sum = 0;
		sort(a,a + n,cmp1);
		d1();
		sort(a,a + n,cmp3);
		d3();
		sort(a,a + n,cmp2);
		d2();
		cnt = max(cnt,sum);
		
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));//2
		sum = 0;
		sort(a,a + n,cmp2);
		d2();
		sort(a,a + n,cmp1);
		d1();
		sort(a,a + n,cmp3);
		d3();
		cnt = max(cnt,sum);
		
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));//3
		sum = 0;
		sort(a,a + n,cmp2);
		d2();
		sort(a,a + n,cmp3);
		d3();
		sort(a,a + n,cmp1);
		d1();
		cnt = max(cnt,sum);
		
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));//4
		sum = 0;
		sort(a,a + n,cmp3);
		d3();
		sort(a,a + n,cmp2);
		d2();
		sort(a,a + n,cmp1);
		d1();
		cnt = max(cnt,sum);
		
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));//5
		sum = 0;
		sort(a,a + n,cmp3);
		d3();
		sort(a,a + n,cmp1);
		d1();
		sort(a,a + n,cmp2);
		d2();
		cnt = max(cnt,sum);
		//6		
		
		cout << cnt << endl;
	} 
	return 0;
} 