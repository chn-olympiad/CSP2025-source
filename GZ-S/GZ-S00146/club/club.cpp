//GZ-S00146 遵义市第四初级中学 廖奕德
#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],s[4],ss[4],sss,f2,f3,i,j;
pair<int,int>b[100005],c[100005];
void dp(int i) {
	if(ss[1]>(n/2)||ss[2]>(n/2)||ss[3]>(n/2))
		return;
	if(i==n+1) {
		sss=max(sss,s[1]+s[2]+s[3]);
		return;
	}
	for(int j=1; j<=3; j++) {
		s[j]+=a[i][j];
		ss[j]++;
		dp(i+1);
		s[j]-=a[i][j];
		ss[j]--;
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		f3=f2=1;
		sss=0;
		cin>>n;
		for(i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)
				f2=0;
			if(a[i][3]!=0)
				f3=0;
		}
		if(f2==1&&f3==1) {
			sort(a[1]+1,a[1]+n+1);
			for(i=n; i>=n/2+1; i++)
				sss+=a[1][i];
		} else if(f3==1) {
			int d[100001];
			for(i=1; i<=n; i++)
				b[i].first=a[i][1],b[i].second=i,d[i]==0;
			for(i=1; i<=n; i++)
				c[i].first=a[i][2],c[i].second=i;
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			for(i=n,j=n; i>=1&&j>=1; i--,j--)
				if(b[i].second==c[j].second)
					sss+=max(b[i].first,c[j].first);
				else {
					while(d[b[i].second]==1)
						i++;
					sss+=b[i].first,d[b[i].second]=1;
					while(d[c[j].second]==1)
						j++;
					sss+=c[j].first,d[c[j].second]=1;
				}
		} else
			dp(1);
		cout <<sss<<endl;
	}
}
