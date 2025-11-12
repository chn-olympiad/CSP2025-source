#include<bits/stdc++.h>
using namespace std;
#define ma_n 5005

bool used[ma_n];
int nu[ma_n],nm[ma_n];
int num,k,n,now;
int maxx[ma_n],lon[ma_n];
set<string>s;
multiset<int>qqq;

void dfs(int num,int k){
	if(num>k){
		now++;
		multiset<int>qq;
		for(int i=1;i<num;i++){
			lon[now]+=nu[i];
			maxx[now]=max(maxx[now],nu[i]);
			qq.insert(nu[i]);
		}
		bool boo=true;
		for(int k=1;k<=maxx[now];k++){
			if(qq.count(k)>qqq.count(k)){
				!boo;
				break;
			}
		}
		qq.clear();
		if((lon[now]>(maxx[now]*2))&&boo) s.insert("1");
		return;
	}
	for(int i=num;i<=n;i++){
		!used[nm[i]];
		nu[num]=nm[i];
		dfs(num+1,k);
	}
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>nm[i];
		qqq.insert(nm[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<(s.size()+5)%998244353;
	return 0;
}
