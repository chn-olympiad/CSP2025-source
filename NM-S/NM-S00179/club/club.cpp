#include<bits/stdc++.h>
using namespace std;
struct m{
	int a,b,c,man;
};
m man[100001];
int mana[100001],manb[100001],manc[100001];
int a1[100001],b1[100001],c1[100001];
int ans[4];
int t,n;
int a,b,c,ansis;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
        cin>>n;
        if(n==2){
        	cin>>man[1].a>>man[1].b>>man[1].c;
        	cin>>man[2].a>>man[2].b>>man[2].c;
        	int kj=man[1].a+man[2].b;
		} else {
        for(int i=1;i<=n;i++){
           cin>>man[i].a>>man[i].b>>man[i].c;
           if(man[i].a>man[i].b&&man[i].a>man[i].c&&a<n/2){
           	  ans[1]+=man[i].a;
           	  a++;
		   } else if(man[i].b>man[i].a&&man[i].b>man[i].c&&b<n/2){
		   	  ans[2]+=man[i].b;
		   	  b++;
		   } else if(man[i].c>man[i].a&&man[i].c>man[i].b&&c<n/2){
		   	  ans[3]+=man[i].c;
		   	  c++;
		   }
        }
        ansis=ans[1]+ans[2]+ans[3];
        a=0;
        b=0;
        c=0;
        ans[1]=0;
        ans[2]=0;
        ans[3]=0;
        for(int i=1;i<=n;i++){
           mana[i]=man[i].a;
           manb[i]=man[i].b;
           manc[i]=man[i].c;
           a1[mana[i]]=i;
           b1[manb[i]]=i;
           c1[manc[i]]=i;
        }
        sort(mana+1,mana+n+1);
        sort(manb+1,manb+n+1);
        sort(manc+1,manc+n+1);
        for(int i=n;i>=1;i--){
        	if(mana[i]>manb[i]&&mana[i]>manc[i]&&a<n/2&&man[a1[mana[i]]].a!=0){
           	  ans[1]+=mana[i];
           	  a++;
              man[a1[mana[i]]].b=0;
              man[a1[mana[i]]].c=0;
		   } else if(manb[i]>mana[i]&&manb[i]>manc[i]&&b<n/2&&man[b1[manb[i]]].b!=0){
		   	  ans[2]+=manb[i];
		   	  b++;
		   	  man[b1[manb[i]]].a=0;
              man[b1[manb[i]]].c=0;
		   } else if(manc[i]>manb[i]&&manc[i]>mana[i]&&c<n/2&&man[c1[manc[i]]].c!=0){
		   	  ans[3]+=manc[i];
		   	  c++;
		   	  man[c1[manc[i]]].b=0;
              man[c1[manc[i]]].a=0;
		   }
		}
		int maxn=max(ansis,ans[1]+ans[2]+ans[3]);
        cout<<maxn<<endl;
        a=0;
        b=0;
        c=0;
        ans[1]=0;
        ans[2]=0;
        ans[3]=0;
		}
	}
	return 0;
}
