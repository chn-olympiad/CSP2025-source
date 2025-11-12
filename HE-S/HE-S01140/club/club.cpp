#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,a,b,c,ans,x,y;
int num[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;ans=0;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			ans+=max(a,b);
			if(a) x++;
			if(b) y++;
			num[i]=b;
		}
		if(!x){
			ans=0;
			sort(num,num+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=num[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
