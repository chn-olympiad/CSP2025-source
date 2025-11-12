#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int s[maxn][4],c1[maxn],c2[maxn],c3[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(s,sizeof(s),0);
		memset(c1,sizeof(c1),0);
		memset(c2,sizeof(c2),0);
		memset(c3,sizeof(c3),0);
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j];
			}
		}
		int maxs=n/2;
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			int maxv=max(max(s[i][1],s[i][2]),s[i][3]);
			ans+=maxv;
			if(s[i][1]==maxv){
				s1++;
				c1[s1]=i;
			}else if(s[i][2]==maxv){
				s2++;
				c2[s2]=i;
			}else{
				s3++;
				c3[s3]=i;
			}
		}
		while(s1>maxs){
			int cha=1e7;
			for(int i=1;i<=s1;i++){
				cha=min(cha,min(s[c1[i]][1]-s[c1[i]][2],s[c1[i]][1]-s[c2[i]][3]));
			}
			int m=0;
			for(int i=1;i<=s1;i++){
				if(cha==min(s[c1[i]][1]-s[c1[i]][2],s[c1[i]][1]-s[c2[i]][3])){
					m=i;
					break;
				}
			}
			for(int i=m;i<=s1-1;i++){
				c1[i]=c1[i+1];
			}
			ans-=cha;
			s1--;
		}
		while(s2>maxs){
			int cha=1e7;
			for(int i=1;i<=s2;i++){
				cha=min(cha,min(s[c2[i]][2]-s[c2[i]][1],s[c2[i]][2]-s[c2[i]][3]));
			}
			int m=0;
			for(int i=1;i<=s2;i++){
				if(cha==min(s[c2[i]][2]-s[c2[i]][1],s[c2[i]][2]-s[c2[i]][3])){
					m=i;
					break;
				}
			}
			for(int i=m;i<=s2-1;i++){
				c2[i]=c2[i+1];
			}
			ans-=cha;
			s2--;
		}
		while(s3>maxs){
			int cha=1e7;
			for(int i=1;i<=s3;i++){
				cha=min(cha,min(s[c3[i]][3]-s[c3[i]][2],s[c3[i]][3]-s[c3[i]][1]));
			}
			int m=0;
			for(int i=1;i<=s3;i++){
				if(cha==min(s[c3[i]][3]-s[c3[i]][2],s[c3[i]][3]-s[c3[i]][1])){
					m=i;
					break;
				}
			}
			for(int i=m;i<=s3-1;i++){
				c3[i]=c3[i+1];
			}
			ans-=cha;
			s3--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*no longer dynamic programming!
by "Jade"
luoyihanzhenhaokan*/