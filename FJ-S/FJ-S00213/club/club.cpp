#include<bits/stdc++.h>
using namespace std;
struct s{
	int ma,ma2,mi=2147483647,w;
}b[100005];
int T,n,a[100005][5],c[5],f,cnt=0,ans;
bool cmp(s x,s y){
	return (x.ma-x.ma2)<(y.ma-y.ma2);
}
void init(){
	c[1]=0;
	c[2]=0;
	c[3]=0;
	ans=0;
	cnt=0;
	for(int i=1;i<=n;i++){
		b[i].ma=0;
		b[i].mi=0x3f;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++){
				if(a[i][j]>b[i].ma){
					b[i].w=j;
					b[i].ma=a[i][j];
				}
				if(a[i][j]<b[i].mi){
					b[i].mi=a[i][j];
				}
			}
			ans+=b[i].ma;
			b[i].ma2=a[i][1]+a[i][2]+a[i][3]-b[i].ma-b[i].mi;
			c[b[i].w]++;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=3;i++){
			if(c[i]>n/2)f=i;
		}
		for(int i=1;i<=n;i++){
			if(cnt==c[f]-n/2)break;
			if(b[i].w==f){
				ans=ans-b[i].ma+b[i].ma2;
				cnt++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
