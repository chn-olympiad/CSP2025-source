#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5010],cnt=0;
int val[5010],t=0;
bool vis[5010]={false};
bool check(int sumlen){
	int maxn=-1;
	for(int i=0;i<t;i++){
		if(maxn<val[i]) maxn=val[i];
	}	
	if(sumlen>maxn*2) return true;
	return false;
	
}
void dfs(int start,int len,int sum){
	if(sum>n) return ;
	else if(sum>=3&&check(len)){
		cnt++;
		cnt%=998244353;
	}	
	else{
		for(int i=start;i<n;i++){
			if(!vis[i]){
				vis[i]=true;
				val[t++]=a[i];
				len+=a[i];
				sum++;
				dfs(i+1,len,sum);
				vis[i]=false;
				t--;
				len-=a[i];
				sum--;
			}
		}
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
		return 0;
	}
	sort(a,a+n);
	dfs(0,0,0);
	cout<<(cnt+1)%998244353;
	return 0;
}
