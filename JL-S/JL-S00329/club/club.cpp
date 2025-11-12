#include <bits/stdc++.h>
using namespace std;
#define N 10005
int a[N] [N];
long long n_sx,t_sx,ans_sx,sum_sx;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld%lld",&t_sx,&n_sx);
	while(t_sx--){
		for(int i=0;i<n_sx;i++){
			for(int j=0;j<n_sx;j++)
				scanf("%d",&a[i][j]);
		}
		for(int i=0;i<t_sx;i++){
			for(int j=0;j<n_sx;j++){
				for(int k=0;k<n_sx;k++){
						if(n_sx/t_sx[k]<n_sx/2||n_sx/t_sx[k]==n_sx/2){
							ans_sx++;
						}else{
							continue;
						}
						printf("%lld",ans_sx);
				}
			}
		}
	}
	return 0;
}
