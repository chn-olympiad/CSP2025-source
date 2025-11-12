//GZ-J00394 蒋木铮 贵阳第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int T,n;
struct Stu{
	int a,b,c;
	bool vis;
}d[N];
bool cmp(Stu a1,Stu a2){
	return a1.a>a2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int sum=0;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>d[i].a>>d[i].b>>d[i].c;
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=d[i].a;
		}
		cout<<sum<<endl; 
	}
	return 0;
} 
