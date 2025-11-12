#include<bits/stdc++.h>
using namespace std;
int t,n,b[5];
struct sg{
	int fs,ph;
}a[100006][5],m[100006]; 
bool cmp(sg x,sg y){
	return x.fs>y.fs;
}
bool cmp1(sg x,sg y){
	return x.fs<y.fs;
}
int kd(){
	int z=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') z=z*10+c-'0',c=getchar();
	return z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=kd();
		int ans=0;
		b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++) m[i]={0,0},a[i][1].fs=kd(),a[i][2].fs=kd(),a[i][3].fs=kd(),a[i][1].ph=1,a[i][2].ph=2,a[i][3].ph=3;
		for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+1+3,cmp);
		for(int i=1;i<=n;i++) ans+=a[i][1].fs,b[a[i][1].ph]++;
		for(int i=1;i<=3;i++)
			if(b[i]>n/2){
				for(int j=1;j<=n;j++) m[j].fs=a[j][1].fs-a[j][2].fs,m[j].ph=a[j][1].ph;
				sort(m+1,m+1+n,cmp1);
				for(int j=1,k=1;j<=n&&k<=b[i]-n/2;j++) 
					if(m[j].ph==i) k++,ans-=m[j].fs;
				break;
			}
		cout<<ans<<'\n';
	}
	return 0;
}