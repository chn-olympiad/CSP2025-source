#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n;
ull ans;
int dx[10]={1,0,0,0,1,0,0,0,1};
ull f[(int)1e5];
ull s[(int)1e5];
ull t[(int)1e5];
//应该是dp，但是我不会写……bfs好歹能拿部分分（估计45）
//不会剪枝
//luogu id:921691
//希望能拿个奖吧
//This is me praying that
//this was the very first page
//not where the storyline ends
//my thoughts will echo your name
//until I see you again

//This night is sparkling
//don't you let it go
//I'm wonderstruck
//blushing all the way home 
//void bfs(int d,int a,int b,int c,int dpm,ull cnt){
//	//cout<<"cnt:"<<cnt<<endl;
//	if(max(a,max(b,c))>n/2){
//	return;};
//	
//	if(d==n){
//	ans=max(ans,cnt);
//	//cout<<"ans:"<<a<<" "<<b<<" "<<c<<" "<<endl;
//	return;}
//	
//	queue<int> q;
//	q.push(1);q.push(2);q.push(3);
//	ull cnt1=cnt;
//	if(d>=0){
//	if(dpm==1)cnt1+=f[d];
//	else if(dpm==2)cnt1+=s[d];
//	else cnt1+=t[d];
//}
//	for(int i=0;i<10;i+=3){
//		int p=q.front();
//		q.pop();
//		bfs(d+1,a+dx[i],b+dx[i+1],c+dx[i+2],p,cnt1);
//		
//	}
//}
void bfs(int d,int a,int b,int c,ull cnt){
	//cout<<"cnt:"<<cnt<<endl;
	if(max(a,max(b,c))>n/2){
	return;};
	
	if(d==n){
	ans=max(ans,cnt);
	//cout<<"ans:"<<a<<" "<<b<<" "<<c<<" "<<endl;
	return;}
	
	queue<int> q;
	q.push(1);q.push(2);q.push(3);
	ull cnt1=cnt;
	for(int i=0;i<10;i+=3){
		int p=q.front();
		q.pop();
		if(p==1)cnt1+=f[d];
	else if(p==2)cnt1+=s[d];
	else cnt1+=t[d];
		bfs(d+1,a+dx[i],b+dx[i+1],c+dx[i+2],cnt1);
		if(p==1)cnt1-=f[d];
	else if(p==2)cnt1-=s[d];
	else cnt1-=t[d];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		n=0;
		ans=0;
		cin>>n;
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
//		int dp[n];
		int flag2=0;
		int flag3=0;
		for(int i=0;i<n;i++){
			cin>>f[i]>>s[i]>>t[i];
			if(s[i]!=0&&!flag2)flag2=1;
			if(s[i]!=0&&!flag3)flag3=1;
		}
		if(!flag2&&!flag3){
			sort(f,f+n,greater<int>());
			ull c=0;
			for(int i=0;i<n/2;i++)c+=f[i];
			cout<<c<<endl;
			continue;
		}
		bfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
} 
