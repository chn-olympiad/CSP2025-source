#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	auto geti=[]{
		int res=0;
		char ch;
		while(isspace(ch=getchar()));
		res=ch^48;
		while(isgraph(ch=getchar()))
			res=res*10+(ch^48);
		return res;
	};
	static int n=geti(),a[30],ans=0;
	for(int i=0;i<n;i++)
		a[i]=geti();
	for(int i=1;i<(1<<n);i++){
		int Max=0,Sum=0,Num=0;
		for(int j=0;j<n;j++)
			if(1&i>>j)
				Max=max(Max,a[j]),Sum+=a[j],Num++;
		if(Sum>(Max<<1)&&Num>2)++ans;
	}
	cout<<ans;
	return 0;
}