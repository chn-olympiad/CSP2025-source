#include<bits/stdc++.h>
using namespace std;

int T,n;
const int N=1e5+5;
int a[N][5];
int f[10];
struct node{
	int id,m;
}s[N];
int cnt;
long long ans;

void dfs(int pos){
	if(pos>n){
		long long sum=0;
		for(int i=1;i<=cnt;i++){
			sum+=a[s[i].id][s[i].m];
		}
		ans=max(ans,sum);
		return;
	}
	
	if(f[1]+1<=n/2){
		f[1]++;
		cnt++;
		s[cnt].id=pos;
		s[cnt].m=1;
		dfs(pos+1);
		cnt--;
		f[1]--;
	}
	
	if(f[2]+1<=n/2){
		f[2]++;
		cnt++;
		s[cnt].id=pos;
		s[cnt].m=2;
		dfs(pos+1);
		cnt--;
		f[2]--;
	}
	
	if(f[3]+1<=n/2){
		f[3]++;
		cnt++;
		s[cnt].id=pos;
		s[cnt].m=3;
		dfs(pos+1);
		cnt--;
		f[3]--;
	}
	
}

int aa[N];
long long dp[N][5]; 
struct node2{
	int xx,yy;
}ax[N];
bool cmp(node2 aa,node2 bb){
	return (aa.xx-aa.yy)>(bb.xx-bb.yy);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--){
		cin>>n;
		bool ff1=0,ff2=0,ff3=0;
		//=1代表这一列不为0 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][1]!=0) ff1=1;
				if(a[i][2]!=0) ff2=1;
				if(a[i][3]!=0) ff3=1;
			}
		}
		if(n>10){
			if(ff1==1 and ff2==0 and ff3==0){//A 
				//在第一列找最大的n/2个，剩下全是0 
				for(int i=1;i<=n;i++) aa[i]=a[i][1];
				sort(aa+1,aa+1+n);
				long long ss=0,gg=0;
				for(int i=n;i>=1;i--){
					gg++;
					if(gg>n/2) break;
					ss+=aa[i];
				}			
				cout<<ss<<endl;
			}else{
				int cnt=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=2;j++){
						cnt++;
						ax[cnt].xx=a[i][1];
						ax[cnt].yy=a[i][2];
					}
				}
				sort(ax+1,ax+1+cnt,cmp);
				long long nn=0;
				for(int i=1;i<=n/2;i++){
					nn+=ax[i].xx;
				}
				for(int i=n/2+1;i<=n;i++){
					nn+=ax[i].yy;
				}
				cout<<nn<<endl;
			}
		}else{//暴搜 
			memset(f,0,sizeof(f));
			ans=0;
			cnt=0;
			dfs(1);
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
}
