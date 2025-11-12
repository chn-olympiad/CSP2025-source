#include <bits/stdc++.h>
using namespace std;
bool flag=1;
int t,n,da,db,dc,p;
struct{
	int ans,id,x,y,z;
}f[100005];
struct{
	int a,b,c;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int qwq=1;qwq<=t;qwq++){
		f[0].ans=0;
		f[0].x=0;
		f[0].y=0;
		f[0].z=0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		if(n==2){
			int b[4],c[4];
			b[1]=a[1].a;
			b[2]=a[1].b;
			b[3]=a[1].c;
			c[1]=a[2].a;
			c[2]=a[2].b;
			c[3]=a[2].c;
			sort(b+1,b+4);
			sort(c+1,c+4);
			p=max(b[2]+c[3],c[2]+b[3]);
			if(b[3]==a[1].a&&c[3]==a[2].a){
				flag=0;
			}
			if(b[3]==a[1].b&&c[3]==a[2].b){
				flag=0;
			}
			if(b[3]==a[1].c&&c[3]==a[2].c){
				flag=0;
			}
			if(flag){
				p=b[3]+c[3];
			}
			cout << p;
			return 0;
		}else{
			for(int i = 1;i <= n;i++){
				da=a[i].a;
				db=a[i].b;
				dc=a[i].c;
				f[i].ans=f[i-1].ans+max(da,max(db,dc));
			}
			cout << f[n].ans;
		}
	} 
	return 0;
}