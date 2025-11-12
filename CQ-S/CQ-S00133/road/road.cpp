#include<bits/stdc++.h>
using namespace std;
long long c[1010],a[20][20101],e[1011][1010],e1[1011][1010],s,s1,s2,n,m,k,fath[10101],it,ans=111000000000000,tans;
long long get_fath(long long w) {
	if(fath[w]==w)
		return w;
	long long temp=get_fath(fath[w]);
	fath[w]=temp;
	return temp;
}
void lian(long long a,long long b) {
	long long t1=get_fath(a),t2=get_fath(b);
	if(t1!=t2) {
		fath[t1]=t2;
	}
}
struct xing {
	long long x,y,z;
} e2[1011101];
bool cmp(xing a,xing b) {
	return a.z<b.z;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(e,0x3f,sizeof(e));
	for(int i=1; i<=m; i++) {
		cin>>s>>s1>>s2;
		e[s][s1]=s2;
		e[s1][s]=s2;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=0; i<=(1<<k)-1; i++) {
		tans=0;
		bool p=0;
		for(int j=1; j<=k; j++) {
			if(((1<<(j-1))&i)!=0) {
				tans+=c[j];
			} else if(c[j]==0) {
				cout<<j<<" "<<i<<" "<<(((1<<(j-1))&i)!=0)<<endl;
				p=1;
				break;
			}
		}
		if(p==0) {
			it=0;
			for(int j=1; j<=n; j++) {
				fath[j]=j;
				for(int l=j+1; l<=n; l++) {
					e1[j][l]=e[j][l];
				}
			}
			for(int j=1; j<=k; j++) {
				if(((1<<(j-1))&i)!=0) {
					for(int l=1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							e1[l][o]=min(e1[l][o],a[j][l]+a[j][o]);
						}
					}
				}
			}
			for(int l=1; l<=n; l++) {
				for(int o=l+1; o<=n; o++) {
					if(e1[l][o]<=10000000002)
						e2[++it]= {l,o,e1[l][o]};
				}
			}
			sort(e2+1,e2+1+it,cmp);
			for(int i=1; i<=it; i++) {
				if(get_fath(e2[i].x)!=get_fath(e2[i].y)) {
					tans+=e2[i].z;
					lian(e2[i].x,e2[i].y);
				}
			}
			ans=min(ans,tans);
			cout<<tans<<endl;
		}
	}
	cout<<ans;
}
