#include<bits/stdc++.h>
using namespace std;
const int N=505,M=505;
int n,m,ans=0;
string sa;
bool s[N];
int a[N];

int lis[N];
bool vis[N],vis2[N];
void dfs(int d){
	if(d>n){
		//这里是真的在乱序生成全排列
		//
//		for(int i = 1 ; i <= n ; ++i)
//			cout<<lis[i]<<" ";
//		cout<<endl;
		//
		int cntin=0,cntout=0;
		memset(vis2,0,sizeof(vis2));
		//cntin:已经录取的人数
		//cntout:已经等不及的人数和被淘汰的人数之和 
		for(int i = 1 ; i <= n ; ++i){
			if(a[lis[i]]>cntout&&!vis2[lis[i]]){
				if(s[lis[i]]){
					++cntin;
					vis2[lis[i]]=1;	
					//
//					cout<<"  in:"<<lis[i]<<"\n";
					//
				}else{
					++cntout;
					vis2[lis[i]]=1;
					//
//					cout<<"2out:"<<lis[i]<<"\n";
					//
				}
			}
//			cout<<"round\n";
		}
		if(cntin>=m)
			++ans;
		return ;
	}
	//今天是谁
	for(int i = 1 ; i <= n ; ++i){
		if(!vis[i]){
			vis[i]=1;
			lis[d]=i;
			dfs(d+1);
			vis[i]=0;
		}
	} 
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>sa;
	for(int i = 1 ; i <= n ; ++i){
		s[i]=((sa[i-1]=='1')?1:0);
	}
	/*
	n<=10
	暴搜，先写这个吧
	 
	m=1:
	至少录取一个人
	用全排列减去一个都录不上的情况 
	 
	
	
	m=n
	要录上每一个人，首先所有s[i]必须都等于1
	然后，排序a[i]
	 
	s[i]=1
	所有人都能做对所有题
	要录指定数量的人， 
	*/ 
	if(n<=100){
		ans=0;
		dfs(1);
		cout<<ans<<endl;
		return 0; 
	}else{
		cout<<0<<endl;
		return 0;
	}
	return 0;
}
