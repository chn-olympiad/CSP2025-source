#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],l[4],ms[100001][3],ans;
int maxn(int x1,int x2,int x3){
	if(x1>=x2&&x1>=x3){
		return 1;
	}if(x2>x1&&x2>=x3){
		return 2;
	}return 3;
}
int max2(int x1,int x2,int x3){
	if((x1>=x2&&x1<=x3)||(x1>=x3&&x1<=x2)){
		return 1;
	}if((x2>=x1&&x2<=x3)||(x2>=x3&&x2<=x1)){
		return 2;
	}return 3;
}
void dfs(int id,int sum){
	if(id==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=2;i++){
		if(l[ms[id][1]]<n/2){
			l[ms[id][1]]++;
			dfs(id+1,sum+a[id][ms[id][1]]);
			l[ms[id][1]]--;
		}
		if(l[ms[id][2]]<n/2){
			l[ms[id][2]]++;
			dfs(id+1,sum+a[id][ms[id][2]]);
			l[ms[id][2]]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;l[1]=l[2]=l[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ms[i][1]=maxn(a[i][1],a[i][2],a[i][3]);
			ms[i][2]=max2(a[i][1],a[i][2],a[i][3]);
			//cout<<ms[i][1]<<' '<<ms[i][2]<<endl;
		}
		dfs(1,0);
		cout<<ans<<endl;
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
*/
