#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,now,big;
struct node{
	int x;int y;int z;
}a[500010],b[500010],c[500010],d[500020];
bool cmp(node p,node o){
	return p.x>=o.x;
}
bool cmp1(node p,node o){
	return p.y>=o.y;
}
bool cmp2(node p,node o){
	return p.z>=o.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		sum=0;
		now=0;
		big=0;
		cin>>m; 
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=m;i++){
		if(a[i].x>=a[i].y &&a[i].x>=a[i].z){
			sum++;
			b[sum].x=a[i].x;
			b[sum].y=a[i].y;
			b[sum].z=a[i].z;
		}
		else if(a[i].x<=a[i].y &&a[i].y>=a[i].z){
			now++;
			c[now].x=a[i].x;
			c[now].y=a[i].y;
			c[now].z=a[i].z;
		}
		else {
			big++;
			d[big].x=a[i].x;
			d[big].y=a[i].y;
			d[big].z=a[i].z;
		}
	}
	sort(b+1,b+1+sum,cmp);
	sort(c+1,c+1+now,cmp1);
	sort(d+1,d+1+big,cmp2);
	if(sum>m/2){
		for(int i=m/2+1;i<=sum;i++){
			if(b[i].y>b[i].z){
				now++;
				c[now].x=b[i].x;
				c[now].y=b[i].y;
				c[now].z=b[i].z;
			}
			else{
				big++;
				d[big].x=b[i].x;
				d[big].y=b[i].y;
				d[big].z=b[i].z;
			}
		}
		sum=m/2;
		
	}
	else if(now>m/2){
		for(int i=m/2+1;i<=now;i++){
			if(c[i].x>c[i].z){
				sum++;
				b[sum].x=c[i].x;
				b[sum].y=c[i].y;
				b[sum].z=c[i].z;
			}
			else{
				big++;
				d[big].x=c[i].x;
				d[big].y=c[i].y;
				d[big].z=c[i].z;
			}
		} 
		now=m/2;
	}
	else if(big>m/2){
		for(int i=m/2+1;i<=big;i++){
			if(d[i].x>d[i].y){
				sum++;
				b[sum].x=d[i].x;
				b[sum].y=d[i].y;
				b[sum].z=d[i].z;
			}
			else{
				now++;
				c[now].x=d[i].x;
				c[now].y=d[i].y;
				c[now].z=d[i].z;
			}
		} 
		big=m/2;
	}
	int ans=0;
	for(int i=1;i<=sum;i++){
		ans+=b[i].x;
	}
	for(int i=1;i<=now;i++){
		ans+=c[i].y;
	}
	for(int i=1;i<=big;i++){
		ans+=d[i].z;
	}
	cout<<ans<<endl;
}
return 0;
} 
