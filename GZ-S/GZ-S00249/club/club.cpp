//GZ-S00249 贵州省黔西第一中学 杜仕壮 
#include<bits/stdc++.h>
using namespace std;
long long d,b,c,sum,maxx1,maxx2,maxx3,t,m,n,cnt,p,s,r,a[100000],v[100000],l[100000];
int hhh(int x){
	for(int j=1;j<=m;j++){
			cin>>p>>s>>r;
			a[j]=p;
			v[j]=s;
			l[j]=r;
		}
		while(c<=m/2&&b<=m/2&&d<=m/2){
			sum++;
			maxx1=0;
			maxx1=max(a[sum],v[sum]);
			maxx2=max(maxx1,l[sum]);
			if(maxx2==a[sum]){
				cnt+=maxx2;
				d++;
			}else if(maxx2==v[sum]){
				cnt+=maxx2;
				b++;
			}else{
				cnt+=maxx2;
				c++;
				}
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m;
		cnt=0;
		hhh(m);
		d=0;
		b=0;
		c=0;
		cout<<cnt<<endl;
	}
	return 0;
}

