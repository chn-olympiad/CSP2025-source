#include<bits/stdc++.h>
using namespace std;
struct club{
	int c1,c2,c3,num;
};
bool f[100005];
long long t,n,a1,a2,a3,ans;
club a[100005],b[100005],c[100005];
bool cmp1(club x,club y){
	return (x.c1-x.c2)>(y.c1-y.c2)||(x.c1-x.c3)>(y.c1-y.c3);
}
bool cmp2(club x,club y){
	return (x.c2-x.c1)>(y.c2-y.c1)||(x.c2-x.c3)>(y.c2-y.c3);
}
bool cmp3(club x,club y){
	return (x.c3-x.c2)>(y.c3-y.c2)||(x.c3-x.c1)>(y.c3-y.c1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a[i].num=i;
			b[i]=a[i];
			c[i]=a[i];
		}
		if(n==2){
			sort(a+1,a+3,cmp1);
			sort(b+1,b+3,cmp2);
			sort(c+1,c+3,cmp3);
		}else{
			sort(a+1,a+1+n,cmp1);
			sort(b+1,b+1+n,cmp2);
			sort(c+1,c+1+n,cmp3);
		}
		for(int i=1;i<=n;i++){
			if(a1<=(n/2)&&f[a[i].num]==0){
				a1++;
				f[i]=1;
				ans+=a[i].c1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a2<=(n/2)&&f[b[i].num]==0){
				a2++;
				f[i]=1;
				ans+=b[i].c2;
			}
		}
		for(int i=1;i<=n;i++){
			if(a3<=(n/2)&&f[c[i].num]==0){
				a3++;
				f[i]=1;
				ans+=c[i].c3;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
