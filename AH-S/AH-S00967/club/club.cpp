#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, t;
ll a[100005][5], d[100005], s[4], y[4];
struct node{
	ll x, id;
}k1[100005], k2[100005], k3[100005];
bool cmp1(node x, node y){
	return min(x.x-a[x.id][2], x.x-a[x.id][3])<min(y.x-a[y.id][2], y.x-a[y.id][3]);
}
bool cmp2(node x, node y){
	return min(x.x-a[x.id][1], x.x-a[x.id][3])<min(y.x-a[y.id][1], y.x-a[y.id][3]);
}
bool cmp3(node x, node y){
	return min(x.x-a[x.id][2], x.x-a[x.id][1])<min(y.x-a[y.id][2], y.x-a[y.id][1]);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
		y[1]=y[2]=y[3]=0;
		s[1]=s[2]=s[3]=0;
        scanf("%d", &n);
        for (int i=1; i<=n; i++){
			a[i][0]=-1;
			for (int j=1; j<=3; j++){
			    scanf("%lld", &a[i][j]);
			    if (a[i][j]>a[i][0]){
					a[i][0]=a[i][j];d[i]=j;
				}
			}
			//cout << a[i]
			if (d[i]==1){
				k1[++s[1]].x=a[i][0];
				k1[s[1]].id=i;
				y[1]+=a[i][0];
			}else if (d[i]==2){
				k2[++s[2]].x=a[i][0];
				k2[s[2]].id=i;
				y[2]+=a[i][0];
			}else if (d[i]==3){
				k3[++s[3]].x=a[i][0];
				k3[s[3]].id=i;
				y[3]+=a[i][0];
			}
		}
		sort(k1+1, k1+s[1]+1, cmp1);
		int m=n/2;
		if (s[1]<=m && s[2]<=m && s[3]<=m){
			printf("%lld\n", y[1]+y[2]+y[3]); 
		}else{
			int s1=s[1], s2=s[2], s3=s[3];
			for (int i=1; i<=s1 && s[1]>m; i++){
				if (a[k1[i].id][2]>a[k1[i].id][3]){
					if (s[2]<m){
						s[2]++; y[2]+=a[k1[i].id][2];
						y[1]-=a[k1[i].id][1];
						s[1]--;
					}
				}else {
					if (s[3]<m){
						s[3]++; y[3]+=a[k1[i].id][3];
						y[1]-=a[k1[i].id][1];
						s[1]--;
					}
				}
			}
			sort(k2+1, k2+s[2]+1, cmp2);
			s2=s[2];
			for (int i=1; i<=s2 && s[2]>m; i++){
                //cout << k2[i].id << ' ';
				if (a[k2[i].id][1]>a[k2[i].id][3]){
					if (s[1]<m){
						s[1]++; y[1]+=a[k2[i].id][1];
						y[2]-=a[k2[i].id][2];
						s[2]--;
					}
			    }else{
					if (s[3]<m){
						s[3]++; y[3]+=a[k2[i].id][3];
						y[2]-=a[k2[i].id][2];
						s[2]--;
					}
				}
			}
			sort(k3+1, k3+s[3]+1, cmp3);
			s3=s[3];
			for (int i=1; i<=s3 && s[3]>m; i++){
				if (a[k3[i].id][1]>a[k3[i].id][2]){
					if (s[1]<m){
						s[1]++; y[1]+=a[k3[i].id][1];
						y[3]-=a[k3[i].id][3];
						s[3]--;
					}
				}else{
					if (s[2]<m){
						s[2]++; y[2]+=a[k3[i].id][2];
						y[3]-=a[k3[i].id][3];
						s[3]--;
					}
				}
			}
            //cout << s[1] << ' ' << s[2] << ' ' << s[3] << ' ';
			printf("%lld\n", y[1]+y[2]+y[3]); 
		}
	}
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
记得调！
成功了！
*/
