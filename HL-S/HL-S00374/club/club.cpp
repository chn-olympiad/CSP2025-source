#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int N = 100004;
void solve();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;//shu ju zu shu
	scanf("%d",&t);
	for (int i = 0;i < t;i++){
		solve();
	}
	return 0;
}
void solve(){
	int k;//cheng yuan shu
	int n[N][3];//mei ge bu men ren de bian hao
	int ans = 0;
	memset(n,0,sizeof(n));//chu shi hua
	scanf("%d",&k);
	for (int i = 1;i <= k;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		n[i][0] = a;
		n[i][1] = b;
		n[i][2] = c;
	}//shu ru shu ju
	int p[3] = {0,0,0};//dang qian ren shu
	vector<int> m[3];//dang qian bian hao
	for (int i = 1;i <= k;i++){
		int mx = n[i][0],mxn = 0,smxn = 0;//zui da zhi,zui da zhi bian hao
		for (int j = 1;j <= 2;j++){
			if (n[i][j] > mx){
				mx = n[i][j];
				mxn = j;
			}
		}//zhao zui da zhi
		if (mxn == 0){
			if (n[i][1] > n[i][2]) smxn = 1;
			else smxn = 2;
		}
		else if (mxn == 1){
			if (n[i][0] > n[i][2]) smxn = 0;
			else smxn = 2;
		}
		else if (mxn == 0){
			if (n[i][0] > n[i][1]) smxn = 0;
			else smxn = 1;
		}//zhao di er da zhi
		
		if (p[mxn] < k/2){
			ans += n[i][mxn];
			p[mxn]++;
			m[mxn].push_back(i);
			//printf("!%d %d\n",mxn,i);
		}
		else{
			int sum = 0,x = -1,y = -1;//zui da zhi,xin ren wei zhi,lao ren wei zhi	
			if (mxn == 0) sum = max(n[i][1],n[i][2]);
			if (mxn == 1) sum = max(n[i][0],n[i][2]);
			if (mxn == 2) sum = max(n[i][0],n[i][1]);
			for (int j = 0;j < p[mxn];j++){
				for (int a = 0;a <= 2;a++){
					if (a != mxn){
						//printf("%d %d %d %d %d %d %d\n",mxn,j,a,n[i][mxn],m[mxn][j],n[m[mxn][j]][a],sum);
						
						if (n[i][mxn] + n[m[mxn][j]][a] > sum){//NMDfkC++
							sum = n[i][mxn] + n[m[mxn][j]][a];
							x = j;
							y = a;//lao xin wei zhi
						}
					
					}
				}
			}
			if (x != -1){
				//printf("!%d %d %d\n",ans,n[m[mxn][x]][mxn],sum);
				ans -= n[m[mxn][x]][x];
				ans += sum;
				m[y].push_back(m[mxn][x]);
				m[mxn][x] = i;
			}
			else{
				ans += n[i][smxn];
			}
		}
		printf("@%d\n",ans);
	}
	printf("%d",ans);
	return ;
}