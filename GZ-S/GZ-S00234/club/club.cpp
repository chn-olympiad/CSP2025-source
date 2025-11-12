//GZ-S00234盘州市第二中学 李浩然 
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct stu{
	int a1,a2,a3;
	int m1,m2,m3;
}p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		int ans=0,d1=0,d2=0,d3=0,d=n/2;
		for(int i=1;i<=n;i++){
			cin>>p[i].a1>>p[i].a2>>p[i].a3;
			p[i].m1=max(p[i].a1,p[i].a2);
			p[i].m1=max(p[i].m1,p[i].a3);
			p[i].m2=min(p[i].a1,p[i].a2);
			p[i].m2=min(p[i].m2,p[i].a3);
			p[i].m3=p[i].a1+p[i].a2+p[i].a3-p[i].m1-p[i].m2;
		}
		for(int i=1;i<=n;i--){
			if(d1<d){
				ans+=p[i].m1;
				d1++;
			}else if(d1>=d&&d2<d){
				ans+=p[i].m2;
				d2++;
			}else if(d2>=d&&d3<d){
				ans+=p[i].m3;
				d3++;
			}else if(d3>=d)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
