#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long anss[100005];
struct node{
	int a1,a2,a3;
}a[N];
int c1[N],c2[N],c3[N],n1=0,n2=0,n3=0,t,n,h=1;
int d(node f,int x){
	if(x==1) return f.a1;
	if(x==2) return f.a2;
	if(x==3) return f.a3;
}
int compare(node f,int x,int y){
	int p=d(f,x),q=d(f,y);
	if(p>q) return x;
	else return y;
}
int ff(node f,int x){
	if(x==1) return d(f,1)-d(f,compare(f,2,3));
	if(x==2) return d(f,2)-d(f,compare(f,1,3));
	if(x==3) return d(f,3)-d(f,compare(f,1,2));
}
void insert(node f,int x,int num){
	if(f.a1==0&&f.a2==0&&f.a3==0) return;
	if(x==1){
		if(n1==n/2){
			int p=compare(a[c1[n1]],2,3),q=compare(f,2,3);
			if(d(f,1)+d(a[c1[n1]],p)-d(a[c1[n1]],1)<=0) insert(f,q,num);
			else{
				insert(a[c1[n1]],p,c1[n1]);
				c1[n1]=num;
				int i=n1-1;
				while(ff(f,x)>ff(a[c1[i]],x)&&i>0){
					int w=c1[i+1];
					c1[i+1]=c1[i];
					c1[i]=w;
					i--;
				}
			}
		}
		else{
			int i=n1;
			n1++;
			c1[n1]=num;
			while(ff(f,x)>ff(a[c1[i]],x)&&i>0){
				int w=c1[i+1];
				c1[i+1]=c1[i];
				c1[i]=w;
				i--;
			}
		}
	}
	if(x==2){
		if(n2==n/2){
			int p=compare(a[c2[n2]],1,3),q=compare(f,1,3);
			if(d(f,2)+d(a[c2[n2]],p)-d(a[c2[n2]],2)<=0) insert(f,q,num);
			else{
				insert(a[c2[n2]],p,c2[n2]);
				c2[n2]=num;
				int i=n2-1;
				while(ff(f,x)>ff(a[c2[i]],x)&&i>0){
					int w=c2[i+1];
					c2[i+1]=c2[i];
					c2[i]=w;
					i--;
				}
			}
		}
		else{
			int i=n2;
			n2++;
			c2[n2]=num;
			while(ff(f,x)>ff(a[c2[i]],x)&&i>0){
				int w=c2[i+1];
				c2[i+1]=c2[i];
				c2[i]=w;
				i--;
			}
		}
	}
	if(x==3){
		if(n3==n/2){
			int p=compare(a[c3[n3]],1,2),q=compare(f,1,2);
			if(d(f,3)+d(a[c3[n3]],p)-d(a[c3[n3]],3)<=0) insert(f,q,num);
			
			else{
				insert(a[c3[n3]],p,c3[n3]);
				c3[n3]=num;
				int i=n3-1;
				while(ff(f,x)>ff(a[c3[i]],x)&&i>0){
					int w=c3[i+1];
					c3[i+1]=c3[i];
					c3[i]=w;
					i--;
				}
			}
		}
		else{
			int i=n3;
			n3++;
			c3[n3]=num;
			while(ff(f,x)>ff(a[c3[i]],x)&&i>0){
				int w=c3[i+1];
				c3[i+1]=c3[i];
				c3[i]=w;
				i--;
			}
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		memset(c3,0,sizeof(c3));
		n1=n2=n3=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			insert(a[i],compare(a[i],compare(a[i],1,2),3),i);
		} 
		for(int i=1;i<=n1;i++) ans+=a[c1[i]].a1;
		for(int i=1;i<=n2;i++) ans+=a[c2[i]].a2;
		for(int i=1;i<=n3;i++) ans+=a[c3[i]].a3;
		anss[h]=ans;
		h++;
	} 
	for(int i=1;i<h;i++) cout<<anss[i]<<endl;
	return 0;
}