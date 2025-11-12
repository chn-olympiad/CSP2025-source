#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int t,n,sum[4];
long long ans;
struct node{
	int a[4];
	int x,y,z;
	int used_max,used_mid,used_min;
}s[MAXN];
bool cmp(node A,node B){
	if(A.used_max!=B.used_max) return A.used_max<B.used_max;
	else{
		return A.x>=B.x;
	}
}
int main(){
//	I love CSP-S;
//  ¼òµ¥µÄÌ°ĞÄ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
			if(s[i].a[1]>=s[i].a[2]&&s[i].a[1]>=s[i].a[3]){
				s[i].used_max=1;
				if(s[i].a[2]>=s[i].a[3]){
					s[i].used_mid=2;
					s[i].used_min=3;
					s[i].x=s[i].a[1]-s[i].a[2];
					s[i].y=s[i].a[2]-s[i].a[3];
					s[i].z=s[i].a[1]-s[i].a[3];
				}else{
					s[i].used_mid=3;
					s[i].used_min=2;
					s[i].x=s[i].a[1]-s[i].a[3];
					s[i].y=s[i].a[3]-s[i].a[2];
					s[i].z=s[i].a[1]-s[i].a[2];
				}
			}else if(s[i].a[2]>=s[i].a[1]&&s[i].a[2]>=s[i].a[3]){
				s[i].used_max=2;
				if(s[i].a[1]>=s[i].a[3]){
					s[i].used_mid=1;
					s[i].used_min=3;
					s[i].x=s[i].a[2]-s[i].a[1];
					s[i].y=s[i].a[1]-s[i].a[3];
					s[i].z=s[i].a[2]-s[i].a[3];
				}else{
					s[i].used_mid=3;
					s[i].used_min=1;
					s[i].x=s[i].a[2]-s[i].a[3];
					s[i].y=s[i].a[3]-s[i].a[1];
					s[i].z=s[i].a[2]-s[i].a[1];
				}
			}else if(s[i].a[3]>=s[i].a[1]&&s[i].a[3]>=s[i].a[2]){
				s[i].used_max=3;
				if(s[i].a[1]>=s[i].a[2]){
					s[i].used_mid=1;
					s[i].used_min=2;
					s[i].x=s[i].a[3]-s[i].a[1];
					s[i].y=s[i].a[1]-s[i].a[2];
					s[i].z=s[i].a[3]-s[i].a[2];
				}else{
					s[i].used_mid=2;
					s[i].used_min=1;
					s[i].x=s[i].a[3]-s[i].a[2];
					s[i].y=s[i].a[2]-s[i].a[1];
					s[i].z=s[i].a[3]-s[i].a[1];
				}
			}
		}
		sort(s+1,s+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<s[i].used_max<<" "<<s[i].a[1]<<" "<<s[i].a[2]<<" "<<s[i].a[3]<<" "<<s[i].x<<endl;
		for(int i=1;i<=n;i++){
			if(sum[s[i].used_max]>=n/2){
				ans+=s[i].a[s[i].used_mid];
				sum[s[i].used_mid]++;
			}else{
				ans+=s[i].a[s[i].used_max];
				sum[s[i].used_max]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
