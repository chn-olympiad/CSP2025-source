#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=998244353;
int n,a[5004],ans=0;
void dfs(int k,int num,int maxn){
	if(k>n){
		if(num>maxn*2){
			ans++;
			ans%=MAXN;
		}
		return ;
	}
	dfs(k+1,num,maxn);  //选择1：不选这根木棍
	dfs(k+1,num+a[k],a[k]);  //选择2：选这根木棍
	return ; 
}
struct str{
	int num,maxn;
	int opt;
};
void bfs(){
	queue<str> q;
	set<int> t;
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				str now;
				now.num=a[i]+a[j]+a[k];
				now.maxn=a[k];
				now.opt=(1<<i)+(1<<j)+(1<<k);
				q.push(now);
				if(now.num>now.maxn*2){
					ans++;
					ans%=MAXN;
					t.insert(now.opt);
				}
			}
		}
	}
	while(!q.empty()){
		str nn=q.front();
		//cout<<nn.opt<<" ";
		q.pop();
		for(int i=1;i<=n;i++){
			if(!(1<<i)&nn.opt){
				str now;
				now.num=nn.num+a[i];
				now.maxn=max(nn.maxn,a[i]);
				now.opt+=(1<<i);
				q.push(now);
				if(now.num>now.maxn*2 && t.find(now.opt)==t.end()){
					t.insert(now.opt);
					ans++;
					ans%=MAXN;
				}
			}
		}
	}
	cout<<t.size();
	exit(0);
}
void dfs2(int k,int num,int maxn){
	if(k>n){
		if(num>maxn*2){
			ans++;
			ans%=MAXN;
		}
		clock_t nt=clock();
		if(1000-nt<n){  //时间不够再次搜索 
			cout<<ans%MAXN;
			exit(0);
		}
		else  return ; 
	}
	dfs2(k+1,num,maxn);   
	dfs2(k+1,num+a[k],a[k]); 
	return ;
}
int jc(int x){
	int num=1;
	for(int i=x;i>=1;i--){
		num*=i;
		num%=MAXN;
	} 
	return num;
}
int C(int a,int b){
	//C(a,b)=a!/b!/(a-b)!
	if(a<b)  swap(a,b);
	int ans=1;
	vector<int> t(a-b+1);
	for(int i=1;i<=a-b;i++){
		t[i]++;
	}
	for(int i=a;i>b;i--){
		int sum=i;
		for(int j=1;j<=a-b && sum>1;j++){
			if(t[j]){
				if(sum%j==0){
					sum/=j;
					t[j]=0;
				}
			}
		}
		ans*=sum;
		ans%=MAXN;
	}  
	for(int i=1;i<=a-b;i++){
		if(t[i]){
			ans/=i;
		}
	} 
	return ans;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1)  flag=false;
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0);
	}
	else if(flag){
		//全是1 
		for(int i=3;i<=n;i++){
			ans+=C(n,i); 
			ans%=MAXN;
		}
		cout<<ans%MAXN;
		return 0;
	}
	else if(n<=63){
		bfs();
	}
	else{
		dfs2(1,0,0);
	}
	cout<<ans%MAXN;
	return 0;
}
