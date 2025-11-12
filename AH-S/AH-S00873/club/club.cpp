#include<bits/stdc++.h>
#define MAXN 100005
int t,n;
using namespace std;
int s[3]={0,0,0};
struct uuu{
	int a;
	int b;
	int c;
	int r;
	
}x[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int op=0;op<t;op++){
		cin>>n;
		s[0]=0,s[1]=0,s[2]=0;
		for(int i=0;i<n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>x[i].b&&x[i].a>x[i].c)x[i].r=0;
			else if(x[i].b>x[i].a&&x[i].c<x[i].b)x[i].r=1;
			else x[i].r=2;
			s[x[i].r]++;
		}
		
		while(s[0]>n/2||s[1]>n/2||s[2]>n/2){
			if(s[0]>n/2){
				int u,l=20005,y;
				for(int i=0;i<n;i++){
					if(x[i].a-x[i].b<l&&x[i].r==0){
						u=i;
						l=x[i].a-x[i].b;
						y=1;
						
					}
					if(x[i].a-x[i].c<l&&x[i].r==0){
						u=i;
						l=x[i].a-x[i].c;
						y=2;
						
					}
				}
				x[u].r=y;
				s[y]++;
				s[0]--;
				
			}
			
			else if(s[1]>n/2){
				int u,l=20005,y;
				for(int i=0;i<n;i++){
					if(x[i].b-x[i].c<l&&x[i].r==1){
						u=i;
						l=x[i].b-x[i].c;
						y=2;
						
					}
					if(x[i].b-x[i].a<l&&x[i].r==1){
						u=i;
						l=x[i].b-x[i].a;
						y=0;
						
					}
				}
				x[u].r=y;
				s[y]++;
				s[1]--;
			}
			
			else if(s[2]>n/2){
				int u,l=20005,y;
				for(int i=0;i<n;i++){
					if(x[i].c-x[i].a<l&&x[i].r==2){
						u=i;
						l=x[i].c-x[i].a;
						y=0;
					}
					if(x[i].c-x[i].b<l&&x[i].r==2){
						u=i;
						l=x[i].c-x[i].b;
						y=1;
					}
				}
				x[u].r=y;
				s[y]++;
				s[2]--;
				
			}
		}
		
		int g=0;
		for(int i=0;i<n;i++){
			if(x[i].r==0)g+=x[i].a;
			if(x[i].r==1)g+=x[i].b;
			if(x[i].r==2)g+=x[i].c;
		}
		cout<<g<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
