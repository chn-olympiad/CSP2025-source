#include<bits/stdc++.h>
using namespace std;
long long a[514514],b[514514],n,m,u,c[514514],p,k;
struct shu{
	long long x,y;
}d[514514];
bool cmp(shu a,shu b){
	if(a.x==b.x){
		return a.y<b.y;
	}else{
		return a.x<b.x;
	}
} 
int er(long long a,long long l,long long r){
	long long zh=(l+r)/2;
	/*if(d[zh].x==a&&d[zh].y<p){
		return zh;
	}
	if(d[zh+1].x==a&&d[zh+1].y<p){
		return zh+1;
	}*/
	if(zh==l){
		return l;
	}//cout<<zh;
	if(d[zh].x>a||d[zh].x==a&&d[zh].y>p){
		return er(a,l,zh);
	}
	if(d[zh].x<a||d[zh].x==a&&d[zh].y<=p){
		return er(a,zh,r);
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<b[1]<<" ";
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		d[i].x=b[i],d[i].y=i;
		//cout<<b[i]<<" ";
	}
	sort(d+1,d+1+n,cmp);
	//cout<<endl;
	for(int i=n;i>=1;i--){
		c[i]=-1;
		p=i;
		u=b[i]^m;
		k=er(u,0,n);
		if(d[k].x==u&&d[k].y<i){
			c[i]=d[k].y;
		}
		k++;
		if(d[k].x==u&&d[k].y<i){
			c[i]=d[k].y;
		}
		//cout<<c[i]<<endl;
	}
	c[0]=-1;
	for(int i=1;i<=n;i++){
		c[i]=max(c[i],c[i-1]);
	}
	long long i=c[n],o=0;
	if(c[n]>0){
		o=1;
		while(i>=0){
		//cout<<i<<" ";			
		i=c[i];
		if(i==-1){
			break;
		}o++;
		}
	}else{
		o=0;
	}
	cout<<o;
	return 0;
}
