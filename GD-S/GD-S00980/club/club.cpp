#include<bits/stdc++.h>
using namespace std;

struct stu{
	int x,y,z;
} a[100005];
bool cmp(stu q,stu p){
	return q.x>p.y;
}
bool cmp2(int q,int p){
	return q>p;
}
int b[100005],c[100005];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i].x >> a[i].y >> a[i].z;
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i].y!=0) flag=false;
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++) sum+=a[i].x;
			cout << sum << endl;
		} else {
			for(int i=1;i<=n;i++) b[i]=a[i].x,c[i]=a[i].y;
			sort(b+1,b+n+1,cmp2), sort(c+1,c+n+1,cmp2);
			int cur1=1,cur2=1,sum=0;
			for(int i=1;i<=n/2;i++){
				if(b[cur1]>c[cur2]) sum+=b[cur1++];
				else sum+=c[cur2++];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
