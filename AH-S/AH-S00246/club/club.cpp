#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}a[100010];
bool cmp(Node x,Node y){
	return x.a>y.a;
}
bool cmp2(Node x,Node y){
	return (x.a-x.b)>(y.a-y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		bool flag=1;
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i]!=0)flag=0;
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i].a;
			cout<<ans<<endl;
		}else{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=a[i].a;
				else ans+=a[i].b;
			}
			cout<<ans<<endl;
	}
    return 0;
}
