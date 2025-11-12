#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a,b,c;
}s[100005];
bool comp(node x,node y){
	return x.a>y.a;
}
bool check()
{
	for(int i=1;i<=n;i++){
		if((s[i].b!=s[i].c)||(s[i].b==s[i].c&&s[i].b!=0)) return 0; 
	} 
	return 1;
}
void test()
{
	int num[4];
	memset(num,0,sizeof(0));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b>>s[i].c;
	int MAXN=n/2,maxn=0;
	
	sort(s+1,s+1+n,comp);
	int max1[100005],max2[100005];
	if(check()){
		sort(s+1,s+1+n,comp);
		for(int i=1;i<=MAXN;i++){
			ans+=s[i].a;
		}
		cout<<ans<<endl;
		return;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) test();
	return 0;
}

