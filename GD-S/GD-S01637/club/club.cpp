#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int T,n;
struct node{
	int a1,a2,a3;
}a[N];
int p[N];
int f[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--){
		memset(f,0,sizeof f);
		memset(p,0,sizeof p);
		long long ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			int a1,a2,a3;
			cin >> a1 >> a2 >> a3;
			a[i] = {a1,a2,a3};
			if(a1>=a2&&a1>=a3)p[i] = 1,f[1]++;
			else if(a2>=a1&&a2>=a3)p[i] = 2,f[2]++;
			else p[i] = 3,f[3]++;
		}
		while(f[1]>n/2||f[2]>n/2||f[3]>n/2){
			if(f[1]>n/2){
				int Min = -0x3f3f3f3f,Minid,To;
				for(int i = 1;i <= n;i++){
					if(p[i]==1){
						if(a[i].a2-a[i].a1>Min)Min = a[i].a2-a[i].a1,Minid = i,To = 2;
						if(a[i].a3-a[i].a1>Min)Min = a[i].a3-a[i].a1,Minid = i,To = 3;
					}
				}
				p[Minid] = To;
				f[1]--;
			}
			if(f[2]>n/2){
				int Min = -0x3f3f3f3f,Minid,To;
				for(int i = 1;i <= n;i++){
					if(p[i]==2){
						if(a[i].a1-a[i].a2>Min)Min = a[i].a1-a[i].a2,Minid = i,To = 1;
						if(a[i].a3-a[i].a2>Min)Min = a[i].a3-a[i].a2,Minid = i,To = 3;
					}
				}
				p[Minid] = To;
				f[2]--;
			}
			if(f[3]>n/2){
				int Min = -0x3f3f3f3f,Minid,To;
				for(int i = 1;i <= n;i++){
					if(p[i]==3){
						if(a[i].a2-a[i].a3>Min)Min = a[i].a2-a[i].a3,Minid = i,To = 2;
						if(a[i].a1-a[i].a3>Min)Min = a[i].a1-a[i].a3,Minid = i,To = 1;
					}
				}
				p[Minid] = To;
				f[3]--;
			}
		}
		for(int i = 1;i <= n;i++){
			if(p[i]==1)ans+=a[i].a1;
			else if(p[i]==2)ans+=a[i].a2;
			else ans+=a[i].a3;
		}
		cout << ans << '\n';
	}
	return 0;
}
