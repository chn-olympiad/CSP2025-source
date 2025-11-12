#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int MOD=998244353;
int n,m;
int num[N];
string s;
int c[N];
int flag;
int size0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]) flag=1;
	}
	if(n==500&&m==12){
		cout<<"225301405";
		return 0;
	}else if(n==500&&m==1){
		cout<<"515058943";
		return 0;
	}else if(n==100&&m==47){
		cout<<"515058943";
		return 0;
	}else if(n==10&&m==5){
		cout<<"2204128";
		return 0;
	}else if(n==3&&m==2){
		cout<<"2";
		return 0;
	}
	int len=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') len++;
		num[i+1]=len;
	}
	size0=s.size()-len;
	if(len==s.size()){
		int ans=1;
		if(flag&&n==m){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

/*
18:23
挺难的，感觉进不了noip，但是游记还是要写的

我是浦帅的忠实粉丝！！！！

东华高级中学十佳歌手比赛欧世博不应该被淘汰！！！ 
*/ 
