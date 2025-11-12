#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int t,n;
struct node{
	int a,b,c;
	bool jh = 0;
}s[MAX]; 
bool cmp(node a,node b){
	return a.a > b.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int maxn = n/2,a1=0,b1=0,c1=0,intol=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			int big=0,s1[3];
			s1[0]=s[i].a,s1[1]=s[2].b,s1[2]=s[i].c;
			sort(s1,s1+3);
			big = s1[2];
			if(big==s[i].a&&a1<maxn)a1++;intol += big;continue;
			if(big==s[i].b&&b1<maxn)b1++;intol += big;continue;
			if(big==s[i].c&&c1<maxn)c1++;intol += big;continue;
		}
		cout<<intol<<endl;
	}
	return 0;
}




