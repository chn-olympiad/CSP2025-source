#include<bits/stdc++.h>
using namespace std;

struct member{
	long long a[3];
}m[10005];



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T,ans[6];
	cin>>T;
	for(int t1 = 1;t1<=T;t1++){
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>m[i].a[0]>>m[i].a[1]>>m[i].a[2];
		}
		int cn[3] = {0,0,0};
		int cm[3][10005];
		int p[3] = {1,1,1};
		long long ca[3] = {0,0,0};
		for(int i = 1;i<=n;i++){
			int xi = 0;
			if(m[i].a[1]>m[i].a[xi])xi = 1;
			if(m[i].a[2]>m[i].a[xi])xi = 2;
			if(cn[xi]+1 <= n/2){
				cm[xi][p[xi]] = i;
				p[xi]++;
				cn[xi]++;
				ca[xi] += m[i].a[xi];
			}else{
				int ni = 1;
				for(int j = 1;j<=p[xi];j++){
					if(m[cm[xi][ni]].a[xi] < m[j].a[xi]){
						ni = j;
					}
				}
				if(m[cm[xi][ni]].a[xi] < m[i].a[xi]){
					ca[xi] = ca[xi]-m[cm[xi][ni]].a[xi]+m[i].a[xi];
					m[cm[xi][ni]].a[xi] = -1;
					swap(m[cm[xi][ni]],m[i]);
					i--;
				}else{
					int mi = 1;
					for(int j = 1;j<=p[xi];j++){
						long long summi = m[cm[xi][mi]].a[0]+m[cm[xi][mi]].a[0]+m[cm[xi][mi]].a[0];
						long long sumj = m[j].a[0]+m[j].a[1]+m[j].a[2];
						if(summi<sumj){
							mi = j;
						}
					}
					long long summi = m[cm[xi][mi]].a[0]+m[cm[xi][mi]].a[0]+m[cm[xi][mi]].a[0];
					long long sumxi = m[xi].a[0]+m[xi].a[1]+m[xi].a[2];
					if(summi>sumxi){
						ca[xi] = ca[xi]-m[cm[xi][mi]].a[xi]+m[i].a[xi];
						m[cm[xi][ni]].a[xi] = -1;
						swap(m[cm[xi][mi]],m[i]);
						i--;
					}else{
						m[i].a[xi] = -1;
						i--;
					}
				}
			}
		ans[t1] = ca[0]+ca[1]+ca[2];
		}
	}
	for(int t1 = 1;t1<=T;t1++){
		cout<<ans[t1]<<"\n";
	}	
	return 0;
}
