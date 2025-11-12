#include<bits/stdc++.h>
using namespace std;
const int N = 2010;

int n,m,k,maxn,minn,nexta[N][210];
string a[N],b[N],c[N],d[N],s1,s2;

void init(int j){
	nexta[j][1] = 0;
	nexta[j][2] = 0;
	int k=0;
	for(int i=2;i<a[j].size();i++){
		while(k>0 and a[j][k+1]!=a[j][i]){
			k = nexta[j][k];
		}
		if(a[j][k+1]==a[j][i]){
			k++;
		}
		nexta[j][i] = k;
	}
}

string check(string a,string b,int c){
	string ans=a;c--;
	for(int i=1;i<a.size();i++){
		if(i>c and i<c+b.size()){
			ans[i] = b[i-c];
		}
	}
	return a;
}

//void solve(){
//	for(int i=1;i<=n;i++){
//		cin >> a[i] >> b[i];
//	}
//	for(int i=1;i<=n;i++)
//		cin >> a[i] >> b[i];
//}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin >> n >> m;
//	if(n>=100){
//		solve();
//		return 0;
//	}
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		a[i] = " "+a[i],b[i] = " "+b[i];
		init(i);
	}
	for(int i=1;i<=m;i++){
		cin >> s1 >> s2;k = s1.size();
		if(s1.size()!=s2.size()){
			cout << 0 << endl;
			continue;
		}maxn = -1,minn = k+1;
		s1 = " "+s1,s2 = " "+s2;
		for(int j=0;j<k;j++){
			if(s1[j]!=s2[j]){
				maxn = max(maxn,j);
				minn = min(minn,j);
			}
		}int ans=0;
		for(int j=1;j<=n;j++){
			if(a[j].size()>k+1)continue;
			for(int x=1,y=1;x<=k;x++){
				if(s1[x]==a[j][y]){
					y++;
					if(y>=a[j].size()){
						y=1;
						if(check(s1,b[j],x-y)==s2){
							ans++;
						}
					}
					continue;
				}
				while(y>1 and s1[x]!=a[j][y])
					y = nexta[j][y-1];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
abcabdabc x

*/
