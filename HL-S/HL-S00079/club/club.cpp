#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
long long f[N], s[N], t[N];
long long T, n, a[N][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long a_num=0, b_num=0, c_num=0, ans=0;
		cin>>n;
		long long mid = n/2;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=3;j++)
				cin>>a[i][j];
		for(int i = 1;i<=n;i++){
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				c_num++;
				ans+=a[i][3];
				t[c_num]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			}
			else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a_num++;
				ans+=a[i][1];
				f[a_num]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				b_num++;
				ans+=a[i][2];
				s[b_num]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
		}
		if(c_num>mid){
			sort(t+1,t+c_num+1);
			for(int i = 1;i<=c_num-mid;i++)
				ans-=t[i];	
		}
		else if(a_num>mid){
			sort(f+1,f+a_num+1);
			for(int i = 1;i<=a_num-mid;i++)
				ans-=f[i];
		}
		else if(b_num>mid){
			sort(s+1,s+b_num+1);
			for(int i = 1;i<=b_num-mid;i++)
				ans-=s[i];	
		}
		cout<<ans<<" ";
	}
    return 0;
}
