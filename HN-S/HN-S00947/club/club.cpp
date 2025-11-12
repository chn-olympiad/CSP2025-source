#include<bits/stdc++.h>
using namespace std;
int t,n,z,d;
struct yy{
	int a;
	int b;
	int c;
	int r;
}m[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int x=1;x<=t;x++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].a>m[i].b){
				d++;
			}
			m[i].r=m[i].a-m[i].b;
		}
		if(n==2){
			int k1=max(m[1].a,max(m[1].b,m[1].c));
			int k2=max(m[2].a,max(m[2].b,m[2].c));
			if(m[1].a==k1&&m[2].a==k2){
				int k3=k1-m[1].a+max(m[1].b,m[1].c);
				int k4=k2-m[2].a+max(m[2].b,m[2].c);
				if(k3>=k4) k1=k3;
				else k2=k4;
			}
			else if(m[1].b==k1&&m[2].b==k2){
				int k3=k1-m[1].b+max(m[1].a,m[1].c);
				int k4=k2-m[2].b+max(m[2].a,m[2].c);
				if(k3>=k4) k1=k3;
				else k2=k4;
			}
			else if(m[1].c==k1&&m[2].c==k2){
				int k3=k1-m[1].c+max(m[1].b,m[1].a);
				int k4=k2-m[2].c+max(m[2].b,m[2].a);
				if(k3>=k4) k1=k3;
				else k2=k4;
			}
			cout<<k1+k2;
			return 0;
		}
		if(m[n].c==m[n].b&&m[n].c==0){
			for(int i=2;i<n;i++)
				for(int j=1;j<i;j++)
					if(m[i].a>m[j].a)
						swap(m[i],m[j]);
			for(int i=1;i<=n/2;i++){
				z+=m[i].a;
			}
		}
		else{
			for(int i=2;i<n;i++)
					for(int j=1;j<i;j++)
						if(m[i].r<m[j].r)
							swap(m[i],m[j]);
			if(d>=n/2){
				for(int i=1;i<=n;i++)
					z+=m[i].a;
				for(int i=n/2+1;i<=n;i++){
					z-=m[i].a;
					z+=m[i].b;
				}	
			}
			else{
				for(int i=1;i<=n;i++)
					z+=m[i].b;
				for(int i=n/2+1;i<=n;i++){
					z-=m[i].b;
					z+=m[i].a;
			}	
		}
		cout<<z;
		d=0;
		z=0;
		}
	}
	return 0;
} 
