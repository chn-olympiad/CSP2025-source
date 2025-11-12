#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn][4];
int n;
int t;
int m1n[maxn],m1x[maxn];
int sum[maxn],sum1[maxn],flag[maxn],op[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		long long ans = 0;
		for(int i = 0;i<n;i++) op[i] = 1e6+10;
		for(int i = 0;i<n;i++) m1n[i] = 1e5+10;
		for(int i = 0;i<n;i++) m1x[i] = -1;
		for(int i = 0;i<n;i++){
			for(int j = 1;j<=3;j++){
				cin>>a[i][j];
			}	
		}
		for(int i = 0;i<n;i++){
			for(int j = 1;j<=3;j++){
				m1x[i] = max(m1x[i],a[i][j]);
				m1n[i] = min(m1n[i],a[i][j]);
				//cout<<m1n[i]<<endl;
			}
		}
		for(int i = 0;i<n;i++)
			for(int j = 1;j<=3;j++)
				if(a[i][j] == m1x[i]) flag[i] = j;
		for(int i = 0;i<n;i++){
			if(a[i][1] == m1x[i]&&a[i][3] == m1n[i]) sum[i] = a[i][2];
			else if(a[i][1] == m1n[i]&&a[i][3] == m1x[i]) sum[i] = a[i][2];
			else if(a[i][2] == m1x[i]&&a[i][3] == m1n[i]) sum[i] = a[i][1];
			else if(a[i][2] == m1n[i]&&a[i][3] == m1x[i]) sum[i] = a[i][1];
			else if(a[i][2] == m1x[i]&&a[i][1] == m1n[i]) sum[i] = a[i][3];
			else if(a[i][1] == m1x[i]&&a[i][2] == m1n[i]) sum[i] = a[i][3];
			//cout<<a[i][1]<<" "<<a[i][3]<<" "<<m1x[i]<<" "<<m1n[i]<<endl;
		}
		for(int i = 0;i<n;i++) sum1[i] = m1x[i]-sum[i];
		//for(int i = 0;i<n;i++) cout<<sum1[i]<<endl;
		for(int i = 0;i<n;i++){
			if(flag[i] == 1) cnt1++;
			if(flag[i] == 2) cnt2++;
			if(flag[i] == 3) cnt3++;
		}
		//for(int i = 0;i<n;i++) cout<<m1x[i]<<endl;
		//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
		for(int i = 0;i<n;i++) ans+=m1x[i];
		int num = 0;
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) {
			cout<<ans<<"\n";
		}
		//cout<<ans<<endl;
		int cq = n/2;
		if(cnt1>cq){
			num = cnt1 - cq;
			for(int i = 0;i<n;i++){
				if(flag[i] == 1) op[i] = sum1[i];
			}
			//cout<<num<<endl;
			sort(op,op+n);
			for(int i = 0;i<num;i++){
				ans-=op[i];
			}
			cout<<ans<<"\n";
		} 
		else if(cnt2>cq){
			num = cnt2 - cq;
			for(int i = 0;i<n;i++){
				if(flag[i] == 2) op[i] = sum1[i];
			}
			//cout<<num<<endl;
			sort(op,op+n);
			for(int i = 0;i<num;i++){
				ans-=op[i];
			}
				cout<<ans<<"\n";
		} 
		else if(cnt3>cq){
			num = cnt3 - cq;
			for(int i = 0;i<n;i++){
				if(flag[i] == 3) op[i] = sum1[i];
			}
			//cout<<num<<endl;
			sort(op,op+n);
			for(int i = 0;i<num;i++){
				ans-=op[i];
			}
			cout<<ans<<"\n";
		}
	}
} 
