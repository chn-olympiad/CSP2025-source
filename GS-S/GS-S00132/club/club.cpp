#include <bits/stdc++.h>
using namespace std;
int t,n,a1=0,a2=0,a3=0,maxmax=0,ans=0,anss[6],cnt=0;
struct abc{
	int a,b,c,max;
}p[100005];
int teshu[100086]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>p[j].a>>p[j].b>>p[j].c;
		}
		for(int j=0;j<n;j++){
			if(p[j].a>p[j].b&&p[j].a>p[j].c){
				p[j].max=1;
				
			}
			if(p[j].b>p[j].a&&p[j].b>p[j].c){
				p[j].max=2;
				
			}
			if(p[j].c>p[j].a&&p[j].c>p[j].b){
				p[j].max=3;
			}
		}
		
		
		
		for(int j=0;j<n;j++){
			if(p[j].max==1&&a1<n/2){
				ans+=p[j].a;
				a1++;
			}
			if(p[j].max==2&&a2<n/2){
				ans+=p[j].b;
				a2++;
			}
			if(p[j].max==3&&a3<n/2){
				ans+=p[j].c;
				a3++;
			}
		}
		if(n!=2){
			anss[i]=ans;
		}else if(n==2){
			teshu[0]=p[0].a+p[1].b;
			teshu[1]=p[0].a+p[1].c;
			teshu[2]=p[0].b+p[1].a;
			teshu[3]=p[0].b+p[1].c;
			teshu[4]=p[0].c+p[1].a;
			teshu[5]=p[0].c+p[1].b;
			sort(teshu,teshu+6);
			anss[i]=teshu[5];			
		}
		
		ans=0;
		a1=0;a2=0;a3=0;
	}
	for(int i=0;i<t;i++){
		cout<<anss[i]<<endl;
	}
	return 0;
}
