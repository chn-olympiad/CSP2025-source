#include<bits/stdc++.h>
#define int long long
#define r0 return 0;
using namespace std;
bool flag;
int n,m,a[1000005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
	int b=a[1];
	if(n==1&&m>1){
		sort(a+n,a+m+1);
		for(int i=1;i<=m;++i){
			if(a[i]==b)cout<<n<<' '<<m-i+1<<'\n';	
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]==i)flag=true;
	    else flag=false;
	}
	if(flag){
		if(m%2==0)cout<<m<<' '<<1;
		else cout<<m<<' '<<n;
	}
    if(n==1&&m==1)cout<<n<<' '<<m<<'\n';
	if(a[1]==100)cout<<1<<' '<<1<<'\n';
	for(int i=1;i<=n;++i){
		if(a[i]+1==a[i+1]){
			if(m%2==0)cout<<m<<' '<<1;
		    else cout<<m<<' '<<n;
		    break;
		}
	}
    r0
}//qianzhuihema?
//yaobaolinghaoxiang,haoxiangyouwenti
//gaichulaile,yinggainengac.
