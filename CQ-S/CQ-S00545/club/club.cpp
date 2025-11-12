#include <bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],zym,h[5],k;
struct somebody{
	long long x,y,p,k;
};
somebody s[100005];
bool cmp(somebody a,somebody b){
	return a.p<b.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		zym=0;
		h[1]=h[2]=h[3]=0;
		for(int i=1;i<=n;i++){
			s[i].x=s[i].y=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>=s[i].x){
					s[i].y=s[i].x;
					s[i].x=a[i][j];
				}
				else if(a[i][j]>s[i].y){
					s[i].y=a[i][j];
				}
			}
			s[i].p=s[i].x-s[i].y;
			zym+=s[i].x;
			if(s[i].x==a[i][1]){
				h[1]++;
				s[i].k=1;
			}
			else if(s[i].x==a[i][2]){
				h[2]++;
				s[i].k=2;
			}
			else{
				h[3]++;
				s[i].k=3;
			}
		}
		if(h[1]<=n/2&&h[2]<=n/2&&h[3]<=n/2){
			cout<<zym<<'\n';
		}
		else{
			if(h[1]>n/2){
				k=1;
			}
			else if(h[2]>n/2){
				k=2;
			}
			else{
				k=3;
			}
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(s[i].k==k){
					zym-=s[i].p;
					h[k]--;
					if(h[k]<=n/2){
						break;
					}
				}
			}
			cout<<zym<<'\n';
		}
	}
	return 0;
}
