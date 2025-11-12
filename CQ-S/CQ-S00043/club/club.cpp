#include<bits/stdc++.h>
using namespace std;
//100+16+0+8=124
//ц╩╬хак 
const int N=1e5+10;

struct point{
	int f,s,t,ch,o1,o2,o3,xb;
}a[N];

bool cmp1(point x,point y){
	if(x.o1!=y.o1){
		return x.o1>y.o1;
	}else{
		return x.ch>y.ch;
	}
}
bool cmp2(point x,point y){
	if(x.o2!=y.o2){
		return x.o2>y.o2;
	}else{
		return x.ch>y.ch;
	}
}
bool cmp3(point x,point y){
	if(x.o3!=y.o3){
		return x.o3>y.o3;
	}else{
		return x.ch>y.ch;
	}
}
int t,b[N],c[5];
long long cnt[5];
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			a[i].xb=i;
			if(a[i].f>=a[i].s&&a[i].f>=a[i].t){
				b[i]=1;
				c[1]++;
				cnt[1]+=a[i].f;
				a[i].ch=min(a[i].f-a[i].s,a[i].f-a[i].t)*-1;
				a[i].o1=1;
			}else if(a[i].s>=a[i].f&&a[i].s>=a[i].t){
				b[i]=2;
				c[2]++;
				cnt[2]+=a[i].s;
				a[i].ch=min(a[i].s-a[i].f,a[i].s-a[i].t)*-1;
				a[i].o2=1;
			}else if(a[i].t>=a[i].f&&a[i].t>=a[i].s){
				b[i]=3;
				c[3]++;
				cnt[3]+=a[i].t;
				a[i].ch=min(a[i].t-a[i].f,a[i].t-a[i].s)*-1;
				a[i].o3=1;
			}
		}
		if(c[1]>n/2){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=c[1]-n/2;i++){
				cnt[1]+=a[i].ch;
			}
		}
		if(c[2]>n/2){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=c[2]-n/2;i++){
				cnt[2]+=a[i].ch;
			}
		}
		if(c[3]>n/2){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=c[3]-n/2;i++){
				cnt[3]+=a[i].ch;
			}
		}
		cout<<cnt[1]+cnt[2]+cnt[3]<<"\n";
	}
	return 0;
}
