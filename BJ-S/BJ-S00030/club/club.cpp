#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=1e5+5;
const int M=1;
const int inf=1e9;

int T;
int n;
int a[N][4];
int cnt[4];
bool fa=true;
int na[N];
int ans;

bool srt(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	while(T--){
		fa = true;
		ans = 0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2]!=0)
				fa = false;
		}
		if(fa){
			for(int i=1;i<=n;i++)
				na[i] = a[i][1];
			sort(na+1,na+n+1,srt);
			for(int i=1;i<=n/2;i++)
				ans+=na[i];
			cout << ans << "\n";
		}
		else if(n==2){
			cout << max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2]))))) << "\n";
		}
		else{
			for(int i=1;i<=n;i++)
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			cout << ans << "\n";
		}
	}
	
	return 0;
}
