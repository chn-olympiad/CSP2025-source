#include<bits/stdc++.h>
using namespace std;
const int N=2e2+1;
struct Point{
	int z,y,x;
}a[N];
int n;
int t;
//今年 T1 和去年 T1 是一个人出的吗？？？ 
bool cmp(Point p,Point q){
	if(p.x!=q.x) return p.x>q.x;
	if(p.y!=q.y) return p.y>q.y;
	return p.z>q.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool sta=0,stb=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0){
				sta=1;
			}
			if(a[i].z!=0){
				stb=1;
			}
		}
		if(n==2){
			cout<<max(max(max(max(a[1].x+a[2].y,a[1].z+a[2].y),a[1].x+a[2].z),a[1].y+a[2].z),max(a[1].y+a[2].x,a[1].z+a[2].x))<<endl;
			continue;
		}
		long long ans=0;
		sort(a+1,a+1+n,cmp);
		if(!sta){
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}else if(!stb){
			int xk=0,yk=0;
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y&&xk!=n/2){
					ans+=a[i].x;
					xk++;
				}else{
					ans+=a[i].y;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
