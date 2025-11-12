#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=2e5+10;
const ll P=998244353;
int n,m,c[N],p[N],ans;
char dc[N];
bool sua;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	sua=1;
	for(int i=1;i<=n;i++)
		cin>>dc[i],sua&=(dc[i]=='1');
	for(int i=1;i<=n;i++)
		cin>>c[i],p[i]=i;
	if(n<=10){
		do{	
			int lu=0;
			for(int i=1;i<=n;i++)
				if(dc[i]=='1'&&c[p[i]]>(i-lu-1)) lu++;
			if(lu>=m)ans=(ans+1)%P;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	return 0;
}
