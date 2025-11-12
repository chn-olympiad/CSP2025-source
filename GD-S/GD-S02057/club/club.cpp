#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int a[N][4],maxx[N][2],s[4],flag[3];
map<int,int> mp,p,mm;//mp部门 p部门喜欢人数 mm满意值最大的人 
struct s{
	map<int,int> m,pp;
}st[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=3;i++) p[i]=0,flag[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			maxx[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
			s[1]=a[i][1],s[2]=a[i][2],s[3]=a[i][3];
			mp[a[i][1]]=1,mp[a[i][2]]=2,mp[a[i][3]]=3;
			sort(s+1,s+4);
			a[i][0]=mp[s[1]];
			p[mp[s[1]]]++;
//			mm[mp[s[1]]]=a[mm[mp[s[1]]]][a[mm][0]]<s[1]?mm[mp[s[1]]]=i:mm[mp[s[1]]]=mm[mp[s[1]]]; 
			for(int j=1;j<=3;j++){
				st[i].m[s[j]]=j;
				st[i].pp[j]=s[j];
			} 
		}
//		for(int i=1;i<=3;i++){
//			if(p[i]<=n/2) flag[i]=1,continue;
//		}
	}
		
	return 0;
} 
