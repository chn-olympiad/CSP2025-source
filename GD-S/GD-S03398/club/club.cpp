#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=1e5+5;
int t,n;
int a1,a2,a3;
int ans;
priority_queue<int> z1,z2,z3;
inline int maxi(const int&s1,const int&s2){
	return s1>s2?s1:s2;
}
int main(){
	freopen("club.in","r",stdin);
	scanf("%d",&t);
	while(t--){
		ans=0;
		while(!z1.empty())z1.pop();
		while(!z2.empty())z2.pop();
		while(!z3.empty())z3.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1>=a2&&a1>=a3){
				ans+=a1;
				z1.push(maxi(a2-a1,a3-a1));
				continue;
			}
			if(a2>=a1&&a2>=a3){
				ans+=a2;
				z2.push(maxi(a1-a2,a3-a2));
				continue;
			}
			ans+=a3;
			z3.push(maxi(a1-a3,a2-a3));
		}
		while(z1.size()>n>>1)
			ans+=z1.top(),z1.pop();
		while(z2.size()>n>>1)
			ans+=z2.top(),z2.pop();
		while(z3.size()>n>>1)
			ans+=z3.top(),z3.pop();
		printf("%d\n",ans);
	}
	return 0;
}
