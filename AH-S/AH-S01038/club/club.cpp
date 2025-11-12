#include<bits/stdc++.h>
using namespace std;
int t;
bool f=1;
struct node{
	int a,b,c;
};
bool cmp(node x,node y){
	return x.a>y.a; 
}
bool bvvd(node x,node y){
	if(x.a!=y.a)return x.a>y.a;
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		node s[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0||s[i].c!=0)f=0;
		}
		if(f==0){
			int cnt=0;
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n/2;i++)cnt+=s[i].a;
			cout<<cnt<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
			cout<<ans<<endl;
		}
	}
	return 0;
}
