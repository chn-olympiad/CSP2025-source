#include<bits/stdc++.h> 
#define endl '\n'
//#define int long long
//#define mod
using namespace std;
const int N=100005;
struct node{
	int cnt,id;
}a[N][5];
int t,n,s[5][N],cnt[N];
bool cmp(node x,node y){
	return x.cnt>y.cnt;
}
bool cmp2(int x,int y){
	return a[x][1].cnt-a[x][2].cnt>a[y][1].cnt-a[y][2].cnt;
}
int suan(){
	int ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=cnt[i];j++){
			ans+=a[s[i][j]][1].cnt;
		}
	}
	return ans;
}
void init(){
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	memset(cnt,0,sizeof(cnt));
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j].cnt,a[i][j].id=j;
			sort(a[i]+1,a[i]+1+3,cmp);
			s[a[i][1].id][++cnt[a[i][1].id]]=i;
		}	
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<suan()<<endl;
			continue;
		}
		if(cnt[1]>n/2){
			sort(s[1]+1,s[1]+1+cnt[1],cmp2);
			for(int i=n/2+1;i<=cnt[1];i++){
				int v=s[1][i];
				if(a[v][2].id==2){
					s[2][++cnt[2]]=v;
				}else s[3][++cnt[3]]=v;
				a[v][1]=a[v][2];
			}
			cnt[1]=n/2;
		}
		if(cnt[2]>n/2){
			sort(s[2]+1,s[2]+1+cnt[2],cmp2);
			for(int i=n/2+1;i<=cnt[2];i++){
				int v=s[2][i];
				if(a[v][2].id==1){
					s[1][++cnt[1]]=v;
				}else s[3][++cnt[3]]=v;
				a[v][1]=a[v][2];
			}
			cnt[2]=n/2;
		}
		if(cnt[3]>n/2){
			sort(s[3]+1,s[3]+1+cnt[3],cmp2);
			for(int i=n/2+1;i<=cnt[3];i++){
				int v=s[3][i];
				if(a[v][2].id==1){
					s[1][++cnt[1]]=v;
				}else s[2][++cnt[2]]=v;
				a[v][1]=a[v][2];
			}
			cnt[3]=n/2;
		}
		cout<<suan()<<endl;
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
