#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],xr[500010],ans,o,z,oz;
bool flag,flag2;
vector<pair<int,int> > v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
		if(a[i]!=1) flag=1;
		if(a[i]>255) flag2=1;
		if(a[i]==1) o++;
		if(a[i]==0) z++;
	}
	if(k==0&&!flag){
		cout<<n;
		return 0;
	}
	if(o+z==n&&k<=1){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i]==a[i-1]){
				oz++;
				a[i]=0;
			}
		}
		cout<<(k?o:z+oz);
		return 0;
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			if((xr[j]^xr[i-1])==k){
				flag=0;
				for(auto l:v){
					if((i>=l.first&&i<=l.second)||(j>=l.first&&j<=l.second)||(i<l.first&&j>l.second)){
						flag=1;
						break;
					}
				}
				if(!flag){
					v.push_back({i,j});
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
