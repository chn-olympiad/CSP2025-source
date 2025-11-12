#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MN 555
#define mod 998244353
#define ll long long
using namespace std;
int n,m;

int rd(){
	char c = getchar();
	while(c!='0'&&c!='1')c=getchar();
	return c-'0';
} 

char ch[MN];
int lu[MN],cnt0,noegger;
int mx[MN];
int bao[13];
void baoli(){
	for(int i = 1;i<=n;i++)bao[i]=i;
	int ans = 0;
	while(1){
		int res = 0,noegg = 0;
		for(int i = 1;i<=n;i++){
			if(noegg>=mx[bao[i]] || !lu[i]){
				noegg++;
			}
			else{
				res++;
			}
		}
		if(res>=m)ans++;
		if(!next_permutation(bao+1,bao+1+n))break;
	}
	cout<<ans;
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	cin>>ch;
	for(int i = 1;i<=n;i++){
		lu[i]=ch[i-1]-'0';
		if(!lu[i])cnt0++;
	}
	for(int i = 1;i<=n;i++){
		cin>>mx[i];
		if(!mx[i])noegger++;
	}
	if(n-cnt0<m||n-noegger<m){
		cout<<0;
		return 0;
	}
	
	ll jc = 1;
	for(int i = 1;i<=n;i++){
		jc=jc*i%mod;
	}
	
	if(n<=10){
		baoli();return 0;
	}
	else if(m==n){
		if(cnt0||noegger){
			cout<<0;
			return 0;
		}
		
		cout<<jc;
		return 0;
	}
	if(cnt0==0&&noegger==0){
		
		cout<<jc;
		return 0;
	}
	if(cnt0>=n-cnt0-noegger)cout<<0;
	else cout<<jc;
	return 0;
}


