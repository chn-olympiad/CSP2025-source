#include<bits/stdc++.h>
using namespace std;

#define M 100005

int T;
int n;
long long ans;

int x,y,z;
int gb1[M],gb2[M],gb3[M];

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int o1=0,o2=0,o3=0;
		ans = 0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x >= y && x >= z){
				ans += x;
				gb1[++o1] = x-max(y,z);
			}
			else if(y >= z && y >= x){
				ans += y;
				gb2[++o2] = y-max(x,z);
			}
			else {
				ans += z;
				gb3[++o3] = z-max(x,y);
			}
		}
		if(o1 > (n/2)){
			sort(gb1 + 1,gb1 + o1 + 1);
			for(int i = 1;i <= o1 - (n/2);i++){
				ans -= gb1[i];
			}
		}
		else if(o2 > (n/2)){
			sort(gb2 + 1,gb2 + o2 + 1);
			for(int i = 1;i <= o2 - (n/2);i++){
				ans -= gb2[i];
			}
		}
		else if(o3 > (n/2)){
			sort(gb3 + 1,gb3 + o3 + 1);
			for(int i = 1;i <= o3 - (n/2);i++){
				ans -= gb3[i];
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
