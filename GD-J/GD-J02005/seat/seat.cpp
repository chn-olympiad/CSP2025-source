#include<bits/stdc++.h>
#define int long long
#define fi(n) for(int i=1;i<=n;i++)
#define fj(n) for(int j=1;j<=n;j++)
using namespace std;
int n,m;
struct stude{
	int score;
	int ming;
}a[105]; 
int tot=0;
bool c[15][15];
bool cmp(stude x,stude y){
	return x.score>y.score;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	fi(n)
		fj(m)
			cin>>a[++tot].score;
	a[1].ming=1;
	sort(a+1,a+n*m+1,cmp);
	
	//fi(n*m) cout<<a[i].score<<' '<<a[i].ming<<"\n"; 
	int l=0;
	fj(m){
		if(j%2==0)
			for(int i=n;i>=1;i--){
				l++;
				if(a[l].ming==1){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		else
			fi(n){
				l++;
				if(a[l].ming==1){
					cout<<j<<' '<<i;
					return 0;
				}
			}
	}
    return 0;
}

