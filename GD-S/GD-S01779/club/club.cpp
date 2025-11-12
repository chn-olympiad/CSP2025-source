#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define db double
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int MAXX=1e5+10;

int T,n,lim;
int a[MAXX][3];
ll b[3][MAXX],R[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		lim=n/2;
		ll res=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int ma=0,sec=0;
			for(int j=0;j<3;j++) {
				if(a[i][j]>=ma) sec=ma,ma=a[i][j];
				else if(a[i][j]>=sec) sec=a[i][j];
			}
			res+=ma;
			for(int j=0;j<3;j++) {
				if(a[i][j]==ma) {
					b[j][++R[j]]=ma-sec;
					break;
				}
			}
		}
		if(R[0]<=lim&&R[1]<=lim&&R[2]<=lim) cout<<res<<'\n';
		else {
			int op=0;
			if(R[1]>lim) op=1;
			else if(R[2]>lim) op=2;
			int num=R[op]-lim;
			sort(b[op]+1,b[op]+1+R[op]);
			for(int i=1;i<=num;i++) res-=b[op][i];
			cout<<res<<'\n';
		}
		for(int j=0;j<3;j++) {
			for(int i=1;i<=n;i++) b[j][i]=0;
		}
		R[0]=R[1]=R[2]=0;
	}

	return 0;
}
