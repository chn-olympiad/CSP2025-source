#include<bits/stdc++.h>
using namespace std;
int n;
int Na[300009];
int suum[300009];
int t;
bool ok[100009];
int sum = 0;
bool AAA = 1;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int asdfgh = 1;asdfgh <= t;asdfgh++){
		int a = 0,b = 0,c = 0;
		sum = 0;
		scanf("%d",&n);
		int ii,i;
		for(ii = 1,i = 1;ii <= n;i+=3,ii++){
			scanf("%d%d%d",&suum[i],&suum[i+1],&suum[i+2]);
			Na[i] = ii;
			Na[i+1] = ii+1000000;
			Na[i+2] = ii+2000000;
			if(suum[i+1] != 0 || suum[i+2] != 0){
				AAA = 0;
			}
			ok[ii] = 0;
		}
		if(AAA){
			sort(suum+1,suum+(n*3)+1);
			for(i = n;i >= n/2+1;i--){
				sum += suum[i];
			}
			cout << sum;
			continue;
		}
		for(i = 1;i <= n*3;i++)
			for(int j = i;j <= n*3;j++)
				if(suum[i] < suum[j]){
					swap(suum[i],suum[j]);
					swap(Na[i],Na[j]);
				}
		for(i = 1;i <= n * 3;i++){
			int ss = Na[i];
			if(ss > 1000000){
				ss -= 1000000;
				if(ss > 1000000){
					ss -= 1000000;
					c++;
					if(c > (n/2)){
						c--;
						continue;
					}
				}
				else {
					b++;
					if(b > (n/2)){
						b--;
						continue;
					}
				}
			}
			else{
				a++;
				if(a > (n/2)){
					a--;
					continue;
				}
			}
			if(!ok[ss]){
				ok[ss] = 1;
				sum += suum[i];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
