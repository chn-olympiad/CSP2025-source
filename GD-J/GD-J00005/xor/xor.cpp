#include <bits/stdc++.h>
using namespace std;
int n,k,l,a,b,cnt,ans,dp[1010][1010];
struct data{
	int x,y;
};
bool cmp(data da,data db){
	if(da.y==db.y)
		 return da.x<db.x;
	else return da.y<db.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1010){
		vector<data> vec;
		for(int i=0;i<n;i++){
			cin>>l;
			for(int j=0;j<=i;j++){
				dp[j][i]=dp[j][i-1]^l;
				if(dp[j][i]==k){
					cnt++;
					vec.push_back({j,i});
				}
			}
		}sort(vec.begin(),vec.end(),cmp);
		l=-1;
		for(int i=0;i<cnt;i++)
			if(l<vec[i].x){
				ans++;
				l=vec[i].y;
			}
		cout<<ans;
		return 0;
	}
	if(n>=1010){
		for(int i=0;i<n;i++){
			cin>>a;
			if(a==k)
				b=0,ans++;
			else if(k==0){
				if(b==1){
					b=0;
					ans++;
				}else b=1;
			}
		}cout<<ans;
		return 0;
	}
	return 0;
}
