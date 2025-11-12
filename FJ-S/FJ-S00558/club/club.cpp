#include<bits/stdc++.h>
using namespace std;
int t, n, N[100005][10], s[300005], len;
long long sum[10];
int x,y,z;
int wb(int a,int b,int c){
	if (a >= b && b >= c) return 1;//(a-b)
	else if(a >= c && c >= b) return 2;//(a-c)
	else if(b >= c && c >= a) return 3;//(b-c)
	else if(b >= a && a >= c) return 4;//(b-a)
	else if(c >= a && a >= b) return 5;//(c-a)
	else if(c >= b && b >= a) return 6;//(c-b)
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++){
		x=y=z=len=0;
		cin >> n;
		memset(s,0,sizeof(s));
		for (int j = 1;j <= n;j++){
			cin >> N[j][1] >> N[j][2] >> N[j][3];
			if(wb(N[j][1],N[j][2],N[j][3]) == 1) N[j][4] = N[j][1]-N[j][2],s[++len] = N[j][4];
			else if(wb(N[j][1],N[j][2],N[j][3]) == 2) N[j][4]=N[j][1]-N[j][3],s[++len] = N[j][4];
			else if(wb(N[j][1],N[j][2],N[j][3]) == 3) N[j][5]=N[j][2]-N[j][3],s[++len] = N[j][5];
			else if(wb(N[j][1],N[j][2],N[j][3]) == 4) N[j][5]=N[j][2]-N[j][1],s[++len] = N[j][5];
			else if(wb(N[j][1],N[j][2],N[j][3]) == 5) N[j][6]=N[j][3]-N[j][1],s[++len] = N[j][6];
			else if(wb(N[j][1],N[j][2],N[j][3]) == 6) N[j][6]=N[j][3]-N[j][2],s[++len] = N[j][6];
		}
		sort(s+1,s+len+1);
		for (int k = len;k >= 1;k--){
			bool v = false;
			for (int j = 1;j <= n;j++){
				if(s[k] == N[j][4]){
					N[j][4] = -1;
					if (x < n/2) x++,sum[i] += N[j][1];
					else sum[i] += max(N[j][2],N[j][3]);
					v = true;
					break;
				}
				else if(s[k] == N[j][5]){
					N[j][5] = -1;
					if (y < n/2) y++,sum[i] += N[j][2];
					else sum[i] += max(N[j][1],N[j][3]);
					v = true;
					break;
				}
				else if(s[k] == N[j][6]){
					N[j][6] = -1;
					if (z < n/2) z++,sum[i] += N[j][3];
					else sum[i] += max(N[j][1],N[j][2]);
					v = true;
					break;
				}
			}
			if (v) continue;
		}
	}
	for (int i = 1;i <= t;i++) cout << sum[i] << endl;
	return 0;
}
