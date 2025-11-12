#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],s[5],ans,ma[100005];
struct ab{
	int w,x;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		vector<ab>v[5];
		ans=0,s[1]=0,s[2]=0,s[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int ss=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				ss=max(ss,a[i][j]);
			} 
			ans+=ss;
			ma[i]=ss;
			if(ss==a[i][1]) s[1]++;
			else if(ss==a[i][2]) s[2]++;
			else if(ss==a[i][3]) s[3]++;
	 	}
	 	for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				v[i].push_back({a[j][i],j});
			}
		}
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				vector<int>h;
				for(auto j:v[i]){
					int b=a[j.x][1],c=a[j.x][2],d=a[j.x][3];
					if(ma[j.x]!=b&&i==1) continue;
					if(ma[j.x]!=c&&i==2) continue;
					if(ma[j.x]!=d&&i==3) continue;
					if(i==1) h.push_back(b-max(c,d));
					if(i==2) h.push_back(c-max(b,d));
					if(i==3) h.push_back(d-max(c,b));
				}
				sort(h.begin(),h.end());
				for(auto j:h){
					s[i]--;
					ans-=j;
					if(s[i]<=n/2) break;
				}
			}
		}
		printf("%d\n",ans);
	}
}
