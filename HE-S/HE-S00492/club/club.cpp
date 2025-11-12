#include<bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
long long t,n,numa,numb,numc,ai,bi,s1,s2,t1,t2,mina,minb,ans;
int p[N][3],tf[N],a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> t;
	while(t > 0){
		t--;
		ans = 0,numa = 0,numb = 0,numc = 0;
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >> p[i][0] >> p[i][1] >> p[i][2];
			
		}
		for(int i = 0;i < n;i++){
			if(p[i][0] >= p[i][1] and p[i][0] >= p[i][2]){
				numa++;
				a[numa] = i;
				tf[i] = 1;
			}
		}
		if(numa + 1 > n / 2){
			for(int i = 0;i < numa + 1 - n / 2;i++){
				mina = -1;
				for(int i = 0;i < numa;i++){
					if(p[i][0] < mina){
						ai = i;
						mina = p[i][0];
					}
					else if(p[i][0] == mina){
						s1 = max(p[ai][1],p[ai][2]);
						s2 = max(p[i][1],p[i][2]);
						if(s1 < s2){
							ai = i;
							mina = p[i][0];
						}
						else if(s1 == s2){
							t1 = min(p[ai][1],p[ai][2]);
							t2 = min(p[i][1],p[i][2]);
							if(t1 < t2){
								ai = i;
								mina = p[i][0];
							}
						}
					}
				}
				if(p[ai][1] > p[ai][2]){
					numb++;
					b[numb] = ai;
				}
				else{
					numc++;
					c[numc] = ai;
				}
				for(int i = ai + 1;i < n;i++){
					a[i - 1] = a[i];
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(p[i][1] >= p[i][2] and tf[i] == 0){
				numb++;
				b[numb] = i;
				tf[i] = 1;
			}
		}
		if(numb + 1 > n / 2){
			for(int i = 0;i < numb + 1 - n / 2;i++){
				minb = -1;
				for(int i = 0;i < numb;i++){
					if(p[i][1] < mina){
						bi = i;
						minb = p[i][1];
					}
					else if(p[i][1] == minb){
						s1 = p[bi][2];
						s2 = p[i][2];
						if(s1 < s2){
							bi = i;
							minb = p[i][1];
						}
					}
				}
				numc++;
				c[numc] = bi;
				for(int i = bi + 1;i < n;i++){
					b[i - 1] = b[i];
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(tf[i] == 0){
				numc++;
				c[numc] = i;
			}
		}
		for(int i = 0;i < numa;i++){
			ans += p[a[i]][0];
		}
		for(int i = 0;i < numb;i++){
			ans += p[b[i]][0];
		}
		for(int i = 0;i < numc;i++){
			ans += p[c[i]][0];
		}
		cout << ans << '\n';
	}
}


