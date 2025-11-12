#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005],z[100005];
struct node{
    int a,b,c;
};
node qwe[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int xt=0,yt=0,zt=0,ans=0;
		for(int j=1;j<=n;j++) cin>>qwe[j].a>>qwe[j].b>>qwe[j].c;
    	for(int j=1;j<=n;j++){
    		if(max(max(qwe[j].a,qwe[j].b),qwe[j].c)==qwe[j].a){xt++;x[xt]=j;ans+=qwe[j].a;}
			else if(max(max(qwe[j].a,qwe[j].b),qwe[j].c)==qwe[j].b){yt++;y[yt]=j;ans+=qwe[j].b;}
			else if(max(max(qwe[j].a,qwe[j].b),qwe[j].c)==qwe[j].c){zt++;z[zt]=j;ans+=qwe[j].c;}
		}
		int s[100005];
		if(xt>n/2){
			for(int k=1;k<=xt;k++){
				if(qwe[x[k]].b>=qwe[x[k]].c) s[k]=qwe[x[k]].a-qwe[x[k]].b;
				else if(qwe[x[k]].c>=qwe[x[k]].b) s[k]=qwe[x[k]].a-qwe[x[k]].c;
			}
			sort(s+1,s+1+xt);
			for(int k=1;k<=xt-n/2;k++) ans-=s[k];
		}
		memset(s,0,sizeof(s));
		if(yt>n/2){
			for(int k=1;k<=yt;k++){
				if(qwe[y[k]].a>=qwe[y[k]].c){
				s[k]=qwe[y[k]].b-qwe[y[k]].a;
		    	}
				else if(qwe[y[k]].c>=qwe[y[k]].a) s[k]=qwe[y[k]].b-qwe[y[k]].c;
			}
			sort(s+1,s+1+yt);
			for(int k=1;k<=yt-n/2;k++) ans-=s[k];
		}
		memset(s,0,sizeof(s));
		if(zt>n/2){
			for(int k=1;k<=zt;k++){
				if(qwe[z[k]].a>=qwe[z[k]].b) s[k]=qwe[z[k]].c-qwe[z[k]].a;
				else if(qwe[z[k]].b>=qwe[z[k]].a) s[k]=qwe[z[k]].c-qwe[z[k]].b;
			}
			sort(s+1,s+1+zt);
			for(int k=1;k<=zt-n/2;k++) ans-=s[k];
		}
		cout<<ans<<endl;
	}
	return 0;
}
