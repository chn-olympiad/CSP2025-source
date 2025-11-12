#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen(polygon.in,"r,stdin");
	freopen(polygon.out,"w,stdout");
	int n;
	cin>>n;
	vector<int>cd(n+1);
	for(int i=1;i<=n;i++) cin>>cd[i];
	sort(cd.begin(),cd.end());
	if(n<=2) cout<<0;
	else if(n==3){
		if(cd[1]+cd[2]+cd[3]>cd[3]*2) cout<<1;
		else cout<<0;
	}
	else{
		int f=0,xz=3,zh=0,qm=0,ans=0;
		while(1){
			f=0;
			qm=1;
			for(int i=1;i<xz;i++){
				f+=cd[i];
				zh=i;
			}
			for(int i=xz;i<=n;i++){
				if(cd[i]<f) ans++;
				else{
					for(int j=zh;j<i;j++){
						f-=cd[qm];
						f+=cd[zh+1];
						zh++;
						qm++;
						if(f>cd[i]) break;
					}
				}
			}
			xz++;
			if(xz>n) break;
		}
		cout<<ans;
	}
	return 0;
}
