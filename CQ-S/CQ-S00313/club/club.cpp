#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}m[100005];
bool cmp1(node a,node b){
	if(a.a-a.b<b.a-b.b){
		return a.a>b.a,a.b>b.b; 
	}
	if(a.a-a.c<b.a-b.c){
		return a.a>b.a,a.c>b.c; 
	}
}
bool cmp2(node a,node b){
	if(a.b-a.c<b.b-b.c){
		return a.b>b.b,a.c>b.c; 
	}
	if(a.b-a.a<b.b-b.a){
		return a.b>b.b,a.a>b.a; 
	}
}
bool cmp3(node a,node b){
	if(a.c-a.a<b.c-b.a){
		return a.c>b.c,a.a>b.a; 
	}
	if(a.c-a.b<b.c-b.b){
		return a.c>b.c,a.b>b.b; 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a1[5]={0,0,0},b1[5]={0,0,0},c1[5]={0,0,0};
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
			int maxn=max(m[i].a,max(m[i].b,m[i].c));
			if(maxn==m[i].a){
				a1[1]+=maxn;
				a1[2]++;
				
			}
			else if(maxn==m[i].b){
				b1[1]+=maxn;
				b1[2]++;
			}
			else{
				c1[1]+=maxn;
				c1[2]++;
			}
		} 
		sort(m+1,m+n+1,cmp3);
		/*for(int i=1;i<=n;i++){
			cout<<m[i].a<<" "<<m[i].b<<" "<<m[i].c<<"\n";
		}*/
		if(a1[2]>n/2){
			for(int i=1;i<=a1[2]-n/2;i++){
				a1[1]-=m[i].a;
				if(m[i].a-m[i].b<=m[i].a-m[i].c&&b1[1]<n/2){
					b1[1]+=m[i].b;
				}
				else if(b1[1]>=n/2){
					c1[1]+=m[i].c;
				}
				if(m[i].a-m[i].c<=m[i].a-m[i].b&&c1[1]<n/2){
					c1[1]+=m[i].c;
				}
				else if(c1[1]>=n/2){
					b1[1]+=m[i].b;
				}
			}
		}
		else if(b1[2]>n/2){
			sort(m+1,m+n+1,cmp2);
			for(int i=1;i<=b1[2]-n/2;i++){
				b1[1]-=m[i].b;
				if(m[i].b-m[i].a<=m[i].b-m[i].c&&a1[1]<n/2){
					a1[1]+=m[i].a;
				}
				else if(a1[1]>=n/2){
					c1[1]+=m[i].c;
				}
				if(m[i].b-m[i].c<=m[i].b-m[i].a&&c1[1]<n/2){
					c1[1]+=m[i].c;
				}
				else if(c1[1]>=n/2){
					a1[1]+=m[i].a;
				}
			}
		}
		 else if(c1[2]>n/2){
		 	sort(m+1,m+n+1,cmp3);
			for(int i=1;i<=c1[2]-n/2;i++){
				c1[1]-=m[i].c;
				if(m[i].c-m[i].b<=m[i].c-m[i].a&&b1[1]<n/2){
					b1[1]+=m[i].b;
				}
				else if(b1[1]>=n/2){
					a1[1]+=m[i].a;
				}
				if(m[i].c-m[i].a<=m[i].c-m[i].b&&a1[1]<n/2){
					a1[1]+=m[i].a;
				}
				else if(a1[1]>=n/2){
					b1[1]+=m[i].b;
				}
			}
		}
		cout<<a1[1]+b1[1]+c1[1]<<"\n"; 
		for(int i=1;i<=100005;i++){
			m[i].a=0;
			m[i].b=0;
			m[i].c=0;
		}
	}
	return 0;
} 
