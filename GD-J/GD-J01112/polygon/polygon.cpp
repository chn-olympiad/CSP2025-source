#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=5005,Mod=998244353;
int n,maxn,a[N],cnt[N],C[N][N],tot=0;
void solve40pts(){
	int lim=1<<n;
	for(int state=1;state<lim;state++){
		int s=state,i=0,sum=0,maxn=0;
		while(s>0){
			if(s&1){
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
			s>>=1,i++;
		}
		if(sum>maxn*2)tot++;
	}
	cout<<tot<<'\n';
	return;
}
void solve24pts(){
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=((ll)C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			tot=(tot+C[i-1][j])%Mod;
		}
	}
	cout<<tot<<'\n';
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		cnt[a[i]]++;
	}
	if(n<=20)solve40pts();
	else if(maxn==1)solve24pts();
	else{
		cout<<"I feel sorry because I can't solve this part of the problem.\n";
	}
	return 0;
}
/*
note:
555不会做
二进制枚举  

BANGING STRIKE!!!
*/
