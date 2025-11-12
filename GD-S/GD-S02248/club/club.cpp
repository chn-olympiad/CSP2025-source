#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct satis{
	int a,b,c;
}sat[100005],at[100500],bt[100500],ct[100500];
int n;

void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&sat[i].a,&sat[i].b,&sat[i].c);
		at[i].a=at[i].b=at[i].c=0;
		bt[i].a=bt[i].b=bt[i].c=0;
		ct[i].a=ct[i].b=ct[i].c=0;
	}
	int suma=0,sumb=0,sumc=0,ans=0;
	int cnta=0,cntb=0,cntc=0;
	bool f;
	for(int i=1;i<=n;i++)
	{
		f=false;
		if(sat[i].a>max(sat[i].b,sat[i].c)){
			if(suma<n/2){
				suma++;
				at[++cnta]=sat[i];
				ans+=sat[i].a;
				f=true;
			}
			else{
				for(int j=1;j<=cnta;j++)
				{
					if(at[j].b>at[j].c){
						if(at[j].a-at[j].b<sat[i].a){
							ans+=(sat[i].a-(at[j].a-at[j].b));
							at[j].b=at[j].c=-1e9;
							at[++cnta]=sat[i];
							f=true;
							break;
						}
					}
					else{
						if(at[j].a-at[j].c<sat[i].a){
							ans+=(sat[i].a-(at[j].a-at[j].c));
							at[j].b=at[j].c=-1e9;
							at[++cnta]=sat[i];
							f=true;
							break;
						}
					}
				}
			}
		}
		else if(sat[i].b>max(sat[i].a,sat[i].c)){
			if(sumb<n/2){
				sumb++;
				bt[++cntb]=sat[i];
				ans+=sat[i].b;
				f=true;
			}
			else{
				for(int j=1;j<=cntb;j++)
				{
					if(bt[j].a>bt[j].c){
						if(bt[j].b-bt[j].a<sat[i].b){
							ans+=(sat[i].b-(bt[j].b-bt[j].a));
							bt[j].a=bt[j].c=-1e9;
							bt[++cntb]=sat[i];
							f=true;
							break;
						}
					}
					else{
						if(at[j].b-at[j].c<sat[i].b){
							ans+=(sat[i].b-(bt[j].b-bt[j].c));
							at[j].a=at[j].c=-1e9;
							bt[++cntb]=sat[i];
							f=true;
							break;
						}
					}
				}
			}
		}
		else{
			if(sumc<n/2){
				sumc++;
				ct[++cntc]=sat[i];
				ans+=sat[i].c;
				f=true;
			}
			else{
				for(int j=1;j<=cntc;j++)
				{
					if(bt[j].a>bt[j].b){
						if(ct[j].c-ct[j].a<sat[i].c){
							ans+=(sat[i].c-(ct[j].c-ct[j].a));
							ct[j].a=ct[j].b=-1e9;
							ct[++cntc]=sat[i];
							f=true;
							break;
						}
					}
					else{
						if(ct[j].c-ct[j].b<sat[i].c){
							ans+=(sat[i].c-(ct[j].c-at[j].b));
							ct[j].a=ct[j].b=-1e9;
							ct[++cntc]=sat[i];
							f=true;
							break;
						}
					}
				}
			}
		}
		if(!f){
			if(sat[i].a>max(sat[i].b,sat[i].c)){
				if(sat[i].b>sat[i].c){
					bt[++cntb]=sat[i];
					ans+=sat[i].b;
				}
				else{
					ct[++cntc]=sat[i];
					ans+=sat[i].c;
				}
			}
			else if(sat[i].b>max(sat[i].a,sat[i].c)){
				if(sat[i].a>sat[i].c){
					at[++cnta]=sat[i];
					ans+=sat[i].a;
				}
				else{
					ct[++cntc]=sat[i];
					ans+=sat[i].c;
				}
			}
			else{
				if(sat[i].a>sat[i].b){
					at[++cnta]=sat[i];
					ans+=sat[i].a;
				}
				else{
					bt[++cntb]=sat[i];
					ans+=sat[i].b;
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}

