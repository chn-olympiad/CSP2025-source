#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int df[N],dt[N],ds[N];
int n,t;
int a[N][5] , b[N][5];
int df_w[N],dt_w[N],ds_w[N];
bool cmp1(int x,int y){
	return df[df_w[x]] > df[df_w[y]];
}
bool cmp2(int x,int y){
	return dt[dt_w[x]] > dt[dt_w[y]];
}
bool cmp3(int x,int y){
	return ds[ds_w[x]] > ds[ds_w[y]];
}
bool nn[N];
int p1(){
	int ans = 0 , d = 1;
	for(int i = 1 ;i <= n ; i++){
		if(df[df_w[i]] == a[df_w[i]][4] && !nn[df_w[i]] && d <= n / 2){
			nn[df_w[i]] = 1;
			ans += df[df_w[i]];
			d++;
		}
	}
	return ans;
}
int p2(){
	int ans = 0 , d = 1;
	for(int i = 1 ;i <= n ; i++){
		if(dt[dt_w[i]] == a[dt_w[i]][4] && !nn[dt_w[i]] && d <= n / 2){
			nn[dt_w[i]] = 1;
			ans += dt[dt_w[i]];
			d++;
		}
	}
	return ans;
}
int p3(){
	int ans = 0 , d = 1;
	for(int i = 1 ;i <= n ; i++){
		if(ds[ds_w[i]] == a[ds_w[i]][4] && !nn[ds_w[i]] && d <= n / 2){
			nn[ds_w[i]] = 1;
			ans += ds[ds_w[i]];
			d++;
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= 3 ; j++){
				scanf("%d",&a[i][j]);
				b[i][j] = j;
			}
			a[i][4] = max( a[i][1] , max( a[i][2] , a[i][3] ) );
			for(int j = 1; j <= n ;j++){
				for(int k = 1 ; k <= 3 ; k++){
					if(a[j][b[j][k]] < a[j][b[j][k+1]])swap(b[j][k] , b[j][k+1]);
				}
			}
		}
		int d1 = 0 , d2 = 0 , d3 = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= 3 ; j++){
				if(b[i][j] == 1){
					df[++d1] = a[i][b[i][j]];
					df_w[d1] = i;
				}
				else if(b[i][j] == 2){
					dt[++d2] = a[i][b[i][j]];
					dt_w[d2] = i;
				}
				else if(b[i][j] == 3){
					ds[++d3] = a[i][b[i][j]];
					ds_w[d3] = i;
				}
			}
		}
		sort(df_w + 1 , df_w + d1 + 1 , cmp1);
		sort(dt_w + 1 , dt_w + d2 + 1 , cmp2);
		sort(ds_w + 1 , ds_w + d3 + 1 , cmp3);
		int ans = 0 , ans1 = 0 , ans2 = 0 , ans3 = 0 , ans4 =0 , ans5 = 0 , ans6 = 0;
		int o=p1(),p=p2(),q=p3();
		ans1 = o + p + q;
		for(int i=1;i<=n;i++)nn[i] = 0;
//		printf("%d %d %d %d\n",ans1,o,p,q);
		o=p1(),q=p3(),p=p2();
		ans2 = o + p + q;
//		printf("%d %d %d %d\n",ans2,o,p,q);
		for(int i=1;i<=n;i++)nn[i] = 0;
		p=p2(),o=p1(),q=p3();
		ans3 = o + p + q;
//		printf("%d %d %d %d\n",ans3,o,p,q);
		for(int i=1;i<=n;i++)nn[i] = 0;
		p=p2(),q=p3(),o=p1();
		ans4 = o + p + q;
//		printf("%d %d %d %d\n",ans4,o,p,q);
		for(int i=1;i<=n;i++)nn[i] = 0;
		q=p3(),o=p1(),p=p2();
		ans5 = o + p + q;
//		printf("%d %d %d %d\n",ans5,o,p,q);
		for(int i=1;i<=n;i++)nn[i] = 0;
		q=p3(),p=p2(),o=p1();
		ans6 = o + p + q;
//		printf("%d %d %d %d\n",ans6,o,p,q);
		ans = max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
		printf("%d\n",ans);
		for(int i = 1 ; i <= n ; i++) {
			nn[i] = df[i] = df_w[i] = dt[i] = dt_w[i] = ds[i] = ds_w[i] = 0;
			a[i][1] = a[i][2] = a[i][3] = 0 ;
			b[i][1] = b[i][2] = b[i][3] = 0;
		}
	}
	return 0;
}

