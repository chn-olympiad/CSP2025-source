#include<bits/stdc++.h>
using namespace std;
#define FILE "xor"
map<int,int> las;
int n,k,ans=0;
int dp[1000001],maxx[1000001];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int summ=0;
	las[0]=0;
	for(int i=1;i<=n;i++){
		int p;
		cin >> p;
		summ^=p;
		if(las.find(summ^k)!=las.end()){
			dp[i]=maxx[las[summ^k]]+1;
			ans=max(ans,dp[i]);
		}
		las[summ]=i;
		maxx[i]=max(maxx[i-1],dp[i]);
	}
	cout << maxx[n];
	return 0;
}
/*
I want to shang mi huo xing wei da shang
//freopen("joker.in","r",stdjoker);
//freopen("chaor.in","r",stdcha)//The pronunciation of "x" is "cha". from our maths teacher 
//freopen("output.out","w",NeverGonnaGiveYouUp);
Arknights
*/
