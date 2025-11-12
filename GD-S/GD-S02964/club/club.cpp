#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

struct student{
	int a[4];
	int fir,mid,lst;
}s[MAXN];

int t,n;
int cnt[4];
long long ans;

bool cmp(student x,student y){
	return x.a[x.lst]>y.a[y.lst]; 
}

void init(int i){
	if (s[i].a[1]>=s[i].a[2]&&s[i].a[1]>=s[i].a[3]) s[i].lst=1;
	if (s[i].a[2]>=s[i].a[1]&&s[i].a[2]>=s[i].a[3]) s[i].lst=2;
	if (s[i].a[3]>=s[i].a[2]&&s[i].a[3]>=s[i].a[1]) s[i].lst=3;
	if (s[i].a[1]<s[i].a[2]&&s[i].a[1]<s[i].a[3]&&s[i].lst!=1) s[i].fir=1;
	if (s[i].a[2]<s[i].a[1]&&s[i].a[2]<s[i].a[3]&&s[i].lst!=2) s[i].fir=2;
	if (s[i].a[3]<s[i].a[2]&&s[i].a[3]<s[i].a[1]&&s[i].lst!=3) s[i].fir=3;
	if (s[i].fir!=1&&s[i].lst!=1) s[i].mid=1;
	if (s[i].fir!=2&&s[i].lst!=2) s[i].mid=2;
	if (s[i].fir!=3&&s[i].lst!=3) s[i].mid=3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while (t--){
		ans=0l;
		for (int i=1;i<=3;i++)
			cnt[i]=0; 
		cin >>n;
		for (int i=1;i<=n;i++){
//			cout <<'!' <<s[i].a[1] <<' ' <<s[i].a[2] <<' ' <<s[i].a[3] <<'\n';
			s[i].fir=s[i].lst=s[i].mid=0;
			cin >>s[i].a[1] >>s[i].a[2] >>s[i].a[3];
			init(i);
			int x=s[i].a[s[i].fir];
			s[i].a[1]-=x,s[i].a[2]-=x,s[i].a[3]-=x,ans+=x;
//			cout <<'!' <<s[i].a[1] <<' ' <<s[i].a[2] <<' ' <<s[i].a[3] <<'\n';
//			cout <<s[i].a[s[i].lst] <<'\n';
		}
		sort(s+1,s+n+1,cmp);
		for (int i=1;i<=n;i++){
			if (cnt[s[i].lst]<n/2) cnt[s[i].lst]++,ans+=s[i].a[s[i].lst];
			else cnt[s[i].mid]++,ans+=s[i].a[s[i].mid];
		}
		cout <<ans <<'\n';
	}
	return 0; 
}
