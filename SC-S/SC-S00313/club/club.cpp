#include<bits/stdc++.h>
using namespace std;
int tt,n,a[100010][5],cnt[5],sum,m[100010],t[20010],maxx,k;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> tt;
	while(tt--){
		cin >> n;
		sum=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		maxx=INT_MIN;
		for(int i=0;i<=20000;i++){
			t[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				sum+=a[i][1];
				m[i]=1;
				cnt[1]++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				sum+=a[i][2];
				m[i]=2;
				cnt[2]++;
			}
			else{
				sum+=a[i][3];
				m[i]=3;
				cnt[3]++;
			}
		}
		if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(m[i]==1){
					k=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
					t[k]++;
					maxx=max(maxx,k);
				}
			}
			n=cnt[1]-n/2;
		}
		else if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(m[i]==2){
					k=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
					t[k]++;
					maxx=max(maxx,k);
				}
			}
			n=cnt[2]-n/2;
		}
		else if(cnt[3]>n/2){
			for(int i=1;i<=n;i++){
				if(m[i]==3){
					k=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
					t[k]++;
					maxx=max(maxx,k);
				}
			}
			n=cnt[3]-n/2;
		}
		else{
			cout << sum << "\n";
			continue;
		}
		for(int i=0;i<=maxx;i++){
			if(t[i]<n){
				n-=t[i];
				sum-=t[i]*i;
			}
			else{
				sum-=n*i;
				break;
			}
		}
		cout << sum << "\n";
	}
	return 0;
} 