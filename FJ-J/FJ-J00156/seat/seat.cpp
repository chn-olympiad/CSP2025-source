#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int n,m;
int s,a[37060];
//int check[100][100];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1) s=a[i];
	}
	
	sort(a+1,a+1+n*m,cmp);
	
	int nowx=1,nowy=1,cnt=1;
	while(nowx<=n && nowy<=m){
		if(a[cnt]==s){
			cout<<nowy<<" "<<nowx<<'\n';
			return 0;
		}
		
		if(nowy%2==1){
			if(nowx==n) nowy++;
			else nowx++;
		}else{
			if(nowx==1) nowy++;
			else nowx--;
		}
		
		cnt++;
	}
	
	return 0;
}
