#include<bits/stdc++.h>

#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define Fol(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pi pair<int,int>
#define se second
#define fi first
#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

#define N 200005

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9')f=(ch=='-'?-1:f),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x/10)write(x/10);
	putchar(x%10+'0');
}

vi A[4];
int a[N][4];

void solve(){
	int n=read();
	For(i,1,3)A[i].clear();
	int ans=0;
	For(i,1,n){
		For(j,1,3)a[i][j]=read();
		int w=max(max(a[i][1],a[i][2]),a[i][3]);
		if(a[i][1]==w){
			ans+=w;A[1].pb(w-max(a[i][2],a[i][3]));
		}
		else if(a[i][2]==w){
			ans+=w;A[2].pb(w-max(a[i][1],a[i][3]));
		}
		else{
			ans+=w;A[3].pb(w-max(a[i][1],a[i][2]));
		}
	}
	For(i,1,3)sort(all(A[i]),[](int x,int y){return x>y;});
	For(i,1,3){
		while(A[i].size()>n/2)ans-=A[i].back(),A[i].pop_back();
	}
	write(ans);putchar('\n');
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();while(T--)solve();
	return 0;
}
