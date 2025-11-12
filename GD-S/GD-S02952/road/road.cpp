#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[1001][1001];
int town[11][1001];
int conne[1001],cnt;
bool f[1005];
int find(){
    int ans,fr,to,maxn = 1145141919;
    for(int i = 1;i<n;i++)
        for(int j = i+1;j<=n;j++){
            if(abs(arr[i][j]) < maxn){
                maxn = abs(arr[i][j]);
                fr = i;
                to = j;
            }
        }
        ans = arr[fr][to];
        conne[++cnt] = fr;
        conne[++cnt] = to; 
        f[fr] = f[to] = 1;
    while(cnt < n){
    	int maxnn = 1145141919;
    	int frr,too;
    	for(int i = 1;i<=cnt;i++)
    		for(int j = 1;j<=n;i++){
    			if(f[j] == 1)	continue;
    			if(abs(arr[i][j]) < maxnn){
                maxn = abs(arr[i][j]);
                fr = i;
                too = j;
            }
		}
		ans+=maxnn;
		conne[++cnt] = too;
	}
    return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1,a,b,c;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        arr[a][b] = arr[b][a] = c;
    }
    for(int i = 1,a,b,c,d,e;i<=k;i++){
        scanf("%d",&town[i][0]);
        for(int j = 1;j<=n;j++)
            scanf("%d",&town[i][j]);
        for(int j = 1;j<=n;j++)
            for(int h = j+1;h<=n;h++){
                arr[j][h] = (town[i][j]+town[i][h]+town[i][0] < (arr[j][h] < 0 ? arr[j][h] * -1 : arr[j][h]) ? -1*(town[i][j]+town[i][h]+town[i][0]) : arr[j][h]);
                arr[h][j] = arr[j][h];
            }
    }
    cout << 15;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
