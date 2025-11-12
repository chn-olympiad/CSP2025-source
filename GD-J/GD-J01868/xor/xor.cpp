#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,pre[N][22];
long long k,arr[N],c,ans=0;
bool dight[22];
int vis[N];
bool check(int l,int r){
	for(int i=0;i<=21;i++){
		if(pre[r][i]-pre[l-1][i]%2!=dight[i])return false;	
	}
	return true;
}
int lowbit(int x){
	return x&-x;
}
void add(int x){
	while(x<=n){
		vis[x]=1;
		x+=lowbit(x);
	}
}
int sum(int x){
	int a=0;
	while(x){
		a+=vis[x];
		x-=lowbit(x);
	}
	return a;
}

int main(){
	memset(pre,0,sizeof(pre));
	memset(dight,0,sizeof(dight));
	memset(vis,0,sizeof(vis));
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	while((1<<cnt)<=k){
		dight[cnt]=k&(1<<cnt);
		cnt++;
	}
	//for(int i=cnt;i>=0;i--)cout<<dight[i]<<' ';
	//cout<<endl;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(!arr[i]&&!k){
			ans++;
			add(i);
		}
	}
	for(int len=0;len<=20;len++){
		for(int i=1;i<=n;i++){
			pre[i][len]=pre[i-1][len];
			if((arr[i]&(1<<len))&&1)pre[i][len]++;
			//cout<<pre[i][len]<<' ';
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum(j)-sum(i-1)!=0)continue;
			if(check(i,j)){
				ans++;
				add(i),add(j);
			}
		}
	}
	cout<<ans;
	//cout<<check(1,4)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
