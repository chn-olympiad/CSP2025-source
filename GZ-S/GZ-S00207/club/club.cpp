//GZ-S00207 曹语心 贵阳市第十八中学 
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+500;
int t,n,s1,s2,ans;
struct book{
	int a,b,c;
}q[N];
bool cmp1(book b1,book b2){
	return b1.a>b2.a;
}
bool cmp2(book b1,book b2){
	return b1.b>b2.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(q,0,sizeof(q));
		s1=0,s2=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			s1+=q[i].a;
			s2+=q[i].b;
		}
		if(s1>s2){
			sort(q+1,q+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=q[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=q[i].b;
			}
			cout<<ans<<endl;
		}else if(s1<s2){
			sort(q+1,q+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=q[i].b;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=q[i].a;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
