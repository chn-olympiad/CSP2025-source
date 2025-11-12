#include<bits/stdc++.h>
using namespace std;
int a[100010][3],c[3],b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		c[0]=c[1]=c[2]=0;
		int sm=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int p=max(a[i][0],max(a[i][1],a[i][2]));
			if(p==a[i][0])c[0]++,b[i]=0;
			else if(p==a[i][1])c[1]++,b[i]=1;
			else c[2]++,b[i]=2;
			sm+=p;
		}
		int p=max(c[0],max(c[1],c[2]));
		int t;
		if(p==c[0])t=0;
		else if(p==c[1])t=1;
		else t=2;
		if(p>n/2){
			vector<int>v;
			for(int i=1;i<=n;i++){
				if(b[i]==t){
					if(t==0)v.push_back(a[i][0]-max(a[i][1],a[i][2]));
					else if(t==1)v.push_back(a[i][1]-max(a[i][0],a[i][2]));
					else v.push_back(a[i][2]-max(a[i][1],a[i][0]));
				}
			}
			sort(v.begin(),v.end());
			for(int i=1;i<=p-n/2;i++)sm-=v[i-1];
		}
		printf("%d\n",sm);
	}
	return 0;
}
