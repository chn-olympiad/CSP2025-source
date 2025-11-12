#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n;
int s[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2]>>s[i][3];
		vector<int> a,b,c;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3]){
				int x=s[i][1]-max(s[i][2],s[i][3]);
				a.push_back(x);
				ans+=s[i][1];
			}
			else if(s[i][2]>=s[i][3]&&s[i][2]>=s[i][1]){
				int x=s[i][2]-max(s[i][1],s[i][3]);
				b.push_back(x);
				ans+=s[i][2];
			}
			else{
				int x=s[i][3]-max(s[i][2],s[i][1]);
				c.push_back(x);
				ans+=s[i][3];
			}
		}
		if((int)a.size()>n/2){
			sort(a.begin(),a.end());
			int len=a.size(),i=0;
			while(len>n/2){
				ans-=a[i];
				i++,len--;
			}
		}
		if((int)b.size()>n/2){
			sort(b.begin(),b.end());
			int len=b.size(),i=0;
			while(len>n/2){
				ans-=b[i];
				i++,len--;
			}
		}
		if((int)c.size()>n/2){
			sort(c.begin(),c.end());
			int len=c.size(),i=0;
			while(len>n/2){
				ans-=c[i];
				i++,len--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
