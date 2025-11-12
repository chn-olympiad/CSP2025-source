#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){int x = 0,ch = getchar();bool zt=0;while(ch<48||ch>57){if(ch==45)zt = 1;ch = getchar();}while(ch>=48&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return zt?-x:x;}
const int N = 1e5 + 10;
int n,ans,t[5];
struct A{int x,id;}a[N][3];
priority_queue<int,vector<int>,greater<int> >q[3]; 
bool cmp(A x,A y){return x.x<y.x;}
void cx(){
	n = read();ans = 0;t[0] = t[1] = t[2] = 0;
	for(int i=0;i<=2;i++)while(!q[i].empty())q[i].pop();
	for(int i=1;i<=n;i++)for(int j=0;j<=2;j++)a[i][j].x = read(),a[i][j].id = j;
	for(int i=1;i<=n;i++)sort(a[i],a[i]+3,cmp);
	for(int i=1;i<=n;i++){
//		cout<<a[i][2].x<<' '<<a[i][1].x<<' '<<a[i][0].x<<' '<<a[i][2].id<<' '<<t[a[i][2].id]<<' '; 
		if(t[a[i][2].id]<n/2){
//			cout<<1<<'\n'; 
			ans += a[i][2].x;t[a[i][2].id]++;
			q[a[i][2].id].push(a[i][2].x-a[i][1].x); 
		}else{
			int x = q[a[i][2].id].top();
			if(x<a[i][2].x-a[i][1].x){
//				cout<<2<<'\n'; 
				ans += a[i][2].x-x;t[a[i][2].id]++;q[a[i][2].id].pop();
				q[a[i][2].id].push(a[i][2].x-a[i][1].x);
			}else ans += a[i][1].x,t[a[i][1].id]++;
		} 
	}cout<<ans<<'\n'; 
}signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q = read();
	while(q--)cx(); 
	return 0;
}
/*
迷惑行为是吧，我让你记
//freopen mian man,what can I say  
 
输验证码被卡了 5min
这键盘手感好差，总是按不出来，红温了 
给我唐完了兄弟
1h 才过 T1 大洋里
感觉 T4 是个神秘的 dp，只打了暴力 
T2 最后 1h 才发现题目看错了，只能祈祷能多骗点分了 
最后 30min，T3 暴力打不完了，只能不可以总司令了，哎。
炸完了 
*/
