#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int s[100005][5],b[5];
bool cmp1(node x1,node y1){
	return x1.x>y1.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0,o=0,l=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			a[i].x=max({s[i][1],s[i][2],s[i][3]});
			a[i].z=min({s[i][1],s[i][2],s[i][3]});
			a[i].y=s[i][1]+s[i][2]+s[i][3]-a[i].x+a[i].z;
			o+=s[i][2],l+=s[i][3];
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++)	ans+=a[i].x;
		cout<<ans;
	}
	return 0;
}
