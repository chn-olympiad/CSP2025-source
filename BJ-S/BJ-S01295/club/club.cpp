#include<bits/stdc++.h>
using namespace std;
int t[5][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		int ans=0,idx1=0,idx2=0,idx3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c,tmp;
			cin>>a>>b>>c;
			tmp=max(a,max(b,c));
			ans+=tmp;
			if(tmp==a) t[1][++idx1]=max(b,c)-a;
			else if(tmp==b) t[2][++idx2]=max(a,c)-b;
			else t[3][++idx3]=max(a,b)-c;
		}
		int tmp=0,len=0;
		if(idx1>n/2) tmp=1,len=idx1;
		else if(idx2>n/2) tmp=2,len=idx2;
		else if(idx3>n/2) tmp=3,len=idx3;
		sort(t[tmp]+1,t[tmp]+1+len);
		for(int i=n/2+1;i<=len;i++) ans+=t[tmp][i];
		cout<<ans<<"\n";
	}
	return 0;
}