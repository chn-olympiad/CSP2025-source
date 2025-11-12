#include<bits/stdc++.h>
using namespace std;
int n,n1,n2,n3,ans;
struct node{
	int x,y,z;
}a[100005],b[100005],c[100005];
bool cmpa(node x,node y){
	int cx,cy;
	if(x.y<=x.x)cx=x.x-x.y;
	if(x.z<=x.x)cx=min(cx,x.x-x.z);
	if(y.y<=y.x)cy=y.x-y.y;
	if(y.z<=y.x)cy=min(cy,y.x-y.z);
	return cx>cy;
}
bool cmpb(node x,node y){
	int cx,cy;
	if(x.x<x.y)cx=x.y-x.x;
	if(x.z<=x.y)cx=min(cx,x.y-x.z);
	if(y.x<y.y)cy=y.y-y.x;
	if(y.z<=y.y)cy=min(cy,y.y-y.z);
	return cx>cy;
}
bool cmpc(node x,node y){
	int cx,cy;
	if(x.x<x.z)cx=x.z-x.x;
	if(x.y<x.z)cx=min(cx,x.z-x.y);
	if(y.x<y.z)cy=y.z-y.x;
	if(y.y<y.z)cy=min(cy,y.z-y.y);
	return cx>cy;
}
void work1(node a[],node b[],node c[],int n1,int n2,int n3){
	sort(a+1,a+n1+1,cmpa);
	for(int i=n1;i>n/2;i--){
		if(a[i].y>=a[i].z){
			n1--;
			ans-=a[i].x;
			ans+=a[i].y;
			b[++n2]=a[i];
		}else{
			n1--;
			ans-=a[i].x;
			ans+=a[i].y;
			c[++n3]=a[i];
		}
	}
	if(n2>n/2){
		sort(b+1,b+n2+1,cmpb);
		for(int i=n2;i>n/2;i--){
			n2--;
			ans-=b[i].y;
			ans+=b[i].z;
			c[++n3]=b[i];
		}
	}
	else if(n3>n/2){
		sort(c+1,c+n3+1,cmpc);
		for(int i=n3;i>n/2;i--){
			n3--;
			ans-=c[i].y;
			ans+=c[i].z;
			b[++n2]=c[i];
		}
	}
}
void work2(node a[],node b[],node c[],int n1,int n2,int n3){
	sort(a+1,a+n1+1,cmpb);
	for(int i=n1;i>n/2;i--){
		if(a[i].x>=a[i].z){
			n1--;
			ans-=a[i].y;
			ans+=a[i].x;
			b[++n2]=a[i];
		}else{
			n1--;
			ans-=a[i].y;
			ans+=a[i].z;
			c[++n3]=a[i];
		}
	}
	if(n2>n/2){
		sort(b+1,b+n2+1,cmpa);
		for(int i=n2;i>n/2;i--){
			n2--;
			ans-=b[i].z;
			ans+=b[i].x;
			c[++n3]=b[i];
		}
	}
	else if(n3>n/2){
		sort(c+1,c+n3+1,cmpa);
		for(int i=n3;i>n/2;i--){
			n3--;
			ans-=c[i].z;
			ans+=c[i].x;
			b[++n2]=c[i];
		}
	}
}
void work3(node a[],node b[],node c[],int n1,int n2,int n3){
	sort(a+1,a+n1+1,cmpc);
	for(int i=n1;i>n/2;i--){
		if(a[i].z>=a[i].x){
			n1--;
			ans-=a[i].y;
			ans+=a[i].z;
			b[++n2]=a[i];
		}else{
			n1--;
			ans-=a[i].y;
			ans+=a[i].x;
			c[++n3]=a[i];
		}
	}
	if(n2>n/2){
		sort(b+1,b+n2+1,cmpa);
		for(int i=n2;i>n/2;i--){
			n2--;
			ans-=b[i].x;
			ans+=b[i].z;
			c[++n3]=b[i];
		}
	}
	else if(n3>n/2){
		sort(c+1,c+n3+1,cmpb);
		for(int i=n3;i>n/2;i--){
			n3--;
			ans-=c[i].z;
			ans+=c[i].x;
			b[++n2]=c[i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=n1=n2=n3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			if(aa>=bb&&aa>=cc){
				a[++n1]={aa,bb,cc};
				ans+=aa;
			}else if(bb>=aa&&bb>=cc){
				b[++n2]={aa,bb,cc};
				ans+=bb;
			}else {
				c[++n3]={aa,bb,cc};
				ans+=cc;
			}
		}
		if(n1>n/2){
			work1(a,b,c,n1,n2,n3);
		}else if(n2>n/2){
			work2(b,c,a,n2,n3,n1);
		}else if(n3>n/2){
			work3(c,a,b,n3,n1,n2);
		}
		cout<<ans<<"\n";	
		
	}
	return 0;
}
