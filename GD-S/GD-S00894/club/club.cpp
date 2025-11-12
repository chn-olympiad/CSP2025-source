#include<bits/stdc++.h>
using namespace std;
int n,t,idx[3]={0,0,0};
struct stu{
	int a[5];
} s[100005];

bool cmp(stu x,stu y){
	return (max(x.a[2],x.a[3])-x.a[1])>(max(y.a[2],y.a[3])-y.a[1]);
}

void solve(){
	cin>>n;
	memset(s,0,sizeof(s));
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
		s[i].a[0]=max(s[i].a[1],max(s[i].a[2],s[i].a[3]));
		sum+=s[i].a[1];
	}
	sort(s+1,s+n+1,cmp);
	int ans=0;
	int g[4]={0,n,0,0};
	for(int i=1;i<=n;i++){
		stu s1=s[i];
		if(sum-s1.a[1]+max(s1.a[2],s1.a[3])>sum||i<=n/2){
			g[1]--;
			if(s1.a[2]>=s1.a[3]&&g[2]<n/2) g[2]++,sum=sum-s1.a[1]+s1.a[2];
			if(s1.a[3]>s1.a[2]&&g[3]<n/2) g[3]++,sum=sum-s1.a[1]+s1.a[3];
		}
	}
	cout<<sum<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
