#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int T,n,a[N][10];
struct Num{
	int x,y,z;
}b[N];
bool cmp(Num a,Num b){
	return (a.x-a.y)>(b.x-b.y);
}
int dfs(string s){
	if(s.size()!=n){
		return max(dfs(s+"1"),max(dfs(s+"2"),dfs(s+"3")));
	}
	else{
		int x=0,b=0,c=0;
		for(auto i:s){
			if(i=='1') x++;
			else if(i=='2') b++;
			else c++;
		}
		if(x<=n/2&&b<=n/2&&c<=n/2){
			int ans=0;
			for(int i = 0;i<s.size();i++){
				ans+=a[i+1][s[i]-'0'];
			}
			return ans;
		}
		else return 0;
	}
}
int solve1(){
	memset(a,0,sizeof(a));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin >> a[i][j];
		}
	}
	return dfs("");
}
int solve2(){
	memset(a,0,sizeof(a));
	for(int i = 1;i<=n;i++){
		cin >> b[i].x >> b[i].y >> b[i].z;
	}
	sort(b+1,b+n+1,cmp);
	int ans=0;
	for(int i = 1;i<=n/2;i++) ans+=b[i].x;
	for(int i = n/2+1;i<=n;i++) ans+=b[i].y;
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		if(n<=10) cout << solve1() << endl;
		else cout << solve2() << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

