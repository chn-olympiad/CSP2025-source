#include<bits/stdc++.h>
using namespace std;
int t;
int a[1000005],b[1000005],c[1000005];
struct sum{
	int id;
	int w;
}aaa[1000005],bbb[1000005],ccc[1000005],bdx[4][1000005];


int cmp(sum a,sum b){
	return a.w > b.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,aa = 0,bb = 0,cc = 0;
		int top = 0,ttop = 0,tttop = 0;
		cin>>n;
		for(int i = 1;i <= 3;++i){
			for(int j = 1;j <= n;++j){
				bdx[i][j].id = 0;
				bdx[i][j].w = 0;
			}
		}
		for(int i = 1;i <= n;++i){
			aaa[i].id = 0;
			bbb[i].id = 0;
			ccc[i].id = 0;
			aaa[i].w = 0;
			bbb[i].w = 0;
			ccc[i].w = 0;
		}
		for(int i = 1;i <= n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if(max(max(a[i],b[i]),c[i]) == a[i]){
				aaa[++top].id = 1;
				aaa[++top].w = a[i];
				aa++;
				bdx[1][i].w = a[i];
				bdx[1][i].id = 1;
				if(b[i] >= c[i]){
					bdx[2][i].w = b[i];
					bdx[3][i].w = c[i];
					bdx[2][i].id = 2;
					bdx[3][i].id = 3;
					
				}
				else{
					bdx[2][i].w = c[i];
					bdx[3][i].w = b[i];
					bdx[2][i].id = 3;
					bdx[3][i].id = 2;
				}
			}
			else if(max(max(a[i],b[i]),c[i]) == b[i]){
				bbb[++ttop].id = 2;
				bbb[++ttop].w = b[i];
				bb++;
				bdx[1][i].w = b[i];
				bdx[1][i].id = 2;
				if(a[i] >= c[i]){
					bdx[2][i].w = a[i];
					bdx[3][i].w = c[i];
					bdx[2][i].id = 1;
					bdx[3][i].id = 3;
				}
				else{
					bdx[2][i].w = c[i];
					bdx[3][i].w = b[i];
					bdx[2][i].id = 3;
					bdx[3][i].id = 1;
				}
			}	
			else{
				ccc[++tttop].id = 3;
				ccc[++tttop].w = c[i];
				cc++;
				bdx[1][i].w = c[i];
				bdx[1][i].id = 3;
				if(a[i] >= b[i]){
					bdx[2][i].w = a[i];
					bdx[3][i].w = b[i];
					bdx[2][i].id = 1;
					bdx[3][i].id = 2;
				}
				else{
					bdx[2][i].w = b[i];
					bdx[3][i].w = a[i];
					bdx[2][i].id = 2;
					bdx[3][i].id = 1;
				}
			}
		}
		int ans = 0,kans = 0;
		if(n == 2){
			if(aa > 1||bb > 1||cc > 1){
				ans += bdx[1][1].w;
				ans += bdx[2][2].w;
				kans += bdx[2][1].w;
				kans += bdx[1][2].w;
				ans = max(ans,kans);
				cout<<ans<<endl;
				continue;
			}
			else{
				cout<<bdx[1][1].w+bdx[1][2].w<<endl;
				continue;
			}
		}
		if(aa <= n/2&&bb <= n/2&&cc <= n/2){
			for(int i = 1;i <= n;++i){
				ans += bdx[1][i].w;
			}
			cout<<ans<<endl;
			continue;
		}
		else{
			sort(aaa+1,aaa+top+1,cmp);
			sort(bbb+1,bbb+ttop+1,cmp);
			sort(ccc+1,ccc+tttop+1,cmp);
			for(int i = 1;i <= n/2;++i){
				ans += aaa[i].w;
				ans += bbb[i].w;
				ans += ccc[i].w;
			} 
			cout<<ans<<endl;
		}
	}
	return 0;
} 
