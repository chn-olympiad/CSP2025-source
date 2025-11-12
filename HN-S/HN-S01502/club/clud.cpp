#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
struct po {
	int x,y,z;
	int MAX,MAXID,MXA2,MAXID2;
} a[N];
bool cmp(po x,po y) {
	return x.MAX>y.MAX;
}
struct ko {
	int UPNAMBER;
	int ans;
};
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {
				a[i].MAX=a[i].x;
				a[i].MAXID=1;
			} else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) {
				a[i].MAX=a[i].y;
				a[i].MAXID=2;
			} else {
				a[i].MAX=a[i].z;
				a[i].MAXID=3;
			}
		}
		int m=n/2;
		int sum=0;
		ko d[4];
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=n; i++) {
			if(d[a[i].MAXID].ans<m) {
				sum+=a[i].MAX;
				d[a[i].MAXID].ans++;
				d[a[i].MAXID].UPNAMBER=i;
			} else {
				if(a[i].x<=a[i].MAX&&a[i].MAXID!=1&&d[1].ans<m&&a[i].x!=0) {
					sum+=a[i].x;
					d[1].ans++;
					d[1].UPNAMBER=i;
				} else if(a[i].y<=a[i].MAX&&a[i].MAXID!=2&&d[2].ans<m&&a[i].y!=0) {
					sum+=a[i].y;
					d[2].ans++;
					d[2].UPNAMBER=i;
				} else if(a[i].x<=a[i].MAX&&a[i].MAXID!=3&&d[3].ans<m&&a[i].z!=0) {
					sum+=a[i].z;
					d[3].ans++;
					d[3].UPNAMBER=i;
				} else{
					int k=d[a[i].MAXID].UPNAMBER;
					if((a[k].x>=a[k].y||a[k].x>=a[k].z)&&a[k].x<=a[k].MAX&&a[k].MAXID!=1&&d[1].ans<m) {
						a[k].MXA2=a[k].x;
						a[k].MAXID2=1;
					} else if((a[k].y>=a[k].x||a[k].y>=a[k].z)&&a[k].y<=a[k].MAX&&a[k].MAXID!=2&&d[2].ans<m) {
						a[k].MXA2=a[k].y;
						a[k].MAXID2=2;
					} else if((a[k].z>=a[k].x||a[k].z>=a[k].y)&&a[k].z<=a[k].MAX&&a[k].MAXID!=3&&d[3].ans<m) {
						a[k].MXA2=a[k].z;
						a[k].MAXID2=3;
					}//57-66查找上一个位置的第二大且可以用的数；
					if(a[k].MAX-a[k].MXA2<a[i].MAX) {
						sum-=a[k].MAX;
						sum+=a[k].MXA2+a[i].MAX;
						d[a[k].MAXID2].ans++;
						d[a[k].MAXID2].UPNAMBER=a[k].MAXID2;
						d[a[i].MAXID].UPNAMBER=a[i].MAXID;
					}
				} //处理有两个零的;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
