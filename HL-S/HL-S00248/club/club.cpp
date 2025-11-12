#include<bits/stdc++.h>
using namespace	std;
long long t,n,d[3],e[3],a[100010],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int x=0,y=0,z=0,sum=0;
		for(int j=1;j<=n;j++){
			a[j]=0;
			b[j]=0;
			c[j]=0;
			cin>>d[1]>>d[2]>>d[3];
			e[1]=d[1];
			e[2]=d[2];
			e[3]=d[3];
			sort(d+1,d+4);
			sum+=d[3];
			if(d[3]==e[1]){
				x++;
				a[x]=d[3]-d[2];
			}else if(d[3]==e[2]){
				y++;
				b[y]=d[3]-d[2];
			}else{
				z++;
				c[z]=d[3]-d[2];
			}
		}
		if(x>n/2){
			sort(a+1,a+x+1);
			for(int j=1;j<=x-n/2;j++){
				sum-=a[j];
			}
		}else if(y>n/2){
			sort(b+1,b+y+1);
			for(int j=1;j<=y-n/2;j++){
				sum-=b[j];
			}
		}else{
			sort(c+1,c+z+1);
			for(int j=1;j<=z-n/2;j++){
				sum-=c[j];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
