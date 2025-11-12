#include<bits/stdc++.h>
using namespace std;

struct node{
	int num,x;
}a[100005][5];
struct big{
	int a1,a2;
}b[100005];
int t,n;
int vis[5];
vector<int> v[5]; 
int sum;
bool cmp(node a,node b){
	if(a.num>=b.num) return 1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j].num;
				a[i][j].x=j;
			}
		}
		for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+4,cmp);
		for(int i=1;i<=n;i++){
			b[i].a1=a[i][1].num-a[i][2].num;
			b[i].a2=a[i][2].num-a[i][3].num;
		}
		for(int i=1;i<=3;i++){
			int x=0;
			for(int j=1;j<=n;j++){
				if(vis[a[j][i].x]<n/2 && vis[1]+vis[2]+vis[3]<=n){
					sum+=a[j][i].num;
					vis[a[j][i].x]++;
					v[a[j][i].x].push_back(a[j][i].num);
				}
				else{
					sort(v,v+v[a[j][i].x].size());
					if(vis[a[j][i].x]>=min(b[v[a[j][i].x][v[a[j][i].x].size()-1]].a1,b[v[a[j][i].x][v[a[j][i].x].size()-1]].a2)){
						if(b[v[a[j][i].x][v[a[j][i].x].size()-1]].a1>=b[v[a[j][i].x][v[a[j][i].x].size()-1]].a2){
							vis[b[v[a[j][i].x][1]].a1]++;
							sum+=abs(a[j][i].x-b[v[a[j][i].x][v[a[j][i].x].size-1]].a1);
							v[a[j][i].x].pop_back();
							if(a[i][j].num>=b[v[a[j][i].x][v[a[j][i].x].size()-1]].a1) v[a[j][i].x].push_back(a[j][i+1].num);
							else v[a[j][i].x].push_back(a[j][i-1].num);
						}
						else{
							vis[b[v[a[j][i].x][1]].a2]++;
							sum+=abs(a[j][i].x-b[v[a[j][i].x][v[a[j][i].x].size-1]].a2);
							v[a[j][i].x].pop_back();
							if(a[i][j].num>=b[v[a[j][i].x][v[a[j][i].x].size()-1]].a2) v[a[j][i].x].push_back(a[j][i+1].num);
							else v[a[j][i].x].push_back(a[j][i-1].num);
						}
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
