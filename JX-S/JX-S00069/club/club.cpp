#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1e5+7;
int T,n,a[N][3],in[N],d[N];
vector<int> s[3];
bool cmp(int q,int w){
	return d[q]>d[w];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		s[0].clear();
		s[1].clear();
		s[2].clear();
		cin>>n;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i][0]=x,a[i][1]=y,a[i][2]=z;
			if(x>y){
				if(x>z){
					s[0].push_back(i);
					in[i]=0;
					d[i]=min(x-y,x-z);
				}
				else{
					s[2].push_back(i);
					in[i]=2;
					d[i]=min(z-x,z-y);
				}
			}
			else{
				if(y>z){
					s[1].push_back(i);
					in[i]=1;
					d[i]=min(y-x,y-z);
				}
				else{
					s[2].push_back(i);
					in[i]=2;
					d[i]=min(z-x,z-y);
				}
			}
		}
		int n0=n/2;
		if(s[0].size()>n0){
			sort(s[0].begin(),s[0].end(),cmp);
			while(s[0].size()>n0){
				int i=s[0][s[0].size()-1];
				s[0].pop_back();
				int y=a[i][1],z=a[i][2];
				if(y>z)in[i]=1;
				else in[i]=2;
			}
		}
		else if(s[1].size()>n0){
			sort(s[1].begin(),s[1].end(),cmp);
			while(s[1].size()>n0){
				int i=s[1][s[1].size()-1];
				s[1].pop_back();
				int x=a[i][0],z=a[i][2];
				if(x>z)in[i]=0;
				else in[i]=2;
			}
		}
		else if(s[2].size()>n0){
			sort(s[2].begin(),s[2].end(),cmp);
			while(s[2].size()>n0){
				int i=s[2][s[2].size()-1];
				s[2].pop_back();
				int x=a[i][0],y=a[i][1];
				if(x>y)in[i]=0;
				else in[i]=1;
			}
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			//cout<<in[i]<<' ';
			ans+=a[i][in[i]];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
