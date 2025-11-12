#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;
int t,n,maxx=-INF,ans;
struct stu{
	int x,y,z;
}a[100005];
int cmp(stu q,stu w){
	return q.x>w.x;
}
int cpp(stu q,stu w){
	return q.y>w.y;
}
int cmm(stu q,stu w){
	return q.z>w.z;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(a+1,a+1+n,cpp);
		sort(a+1,a+1+n,cmm);
		for(int i=1;i<=n;i++){
			int sss=0,bbb=0,lll=0;
			if(sss<(n/2)){
				if(max({a[i].x,a[i].y,a[i].z})==a[i].x){
					ans+=a[i].x;
					sss++;				
				}
			}
			else {
				if(bbb<(n/2)){
					if(max({a[i].y,a[i].z})==a[i].y){
						ans+=a[i].y;
						bbb++;
					}
				}
				else{
					lll++; 		
					ans+=a[i].z;
				}		
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

