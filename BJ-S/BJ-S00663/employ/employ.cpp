#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
bool d[505];//第i天能否应聘
int c[505];//第i个人的耐心值
int a[505];//表示第i天来应聘人的编号
int mp[505];//表示第i号人有没有被搜到
bool A=1;
void dfs(int i){
	if(i>n){//对于这个顺序，判断是否可行
		int agr=0,sum=0;
		for(int i=1;i<=n;i++){
			int ptt=c[a[i]];
			if(agr<ptt&&d[i]==1){
				sum++;
			}
			else{
				agr++;
			}
		}
		if(sum>=m){
			ans++;
		}
		return ;
	}
	else{//搜索所有顺序
		for(int j=1;j<=n;j++){
			if(mp[j]==0){
				a[i]=j;
				mp[j]=1;
				dfs(i+1);
				mp[j]=0;
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	 cin>>n>>m;
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		d[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		dfs(1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
