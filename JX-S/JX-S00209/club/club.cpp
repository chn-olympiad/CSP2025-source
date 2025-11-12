#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int k1[100005],tot1;
int k2[100005],tot2;
int k3[100005],tot3;
priority_queue< pair<int,int> >k;
int d1[100005],d2[100005],d3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,tot1=0,tot2=0,tot3=0;
        memset(k1,0,sizeof(k1));
        memset(k2,0,sizeof(k2));
        memset(k3,0,sizeof(k3));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        memset(d3,0,sizeof(d3));
        while(!k.empty())k.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
            cin>>d1[i]>>d2[i]>>d3[i];
        }
		for(int i=1;i<=n;i++){
		    int ma=0;
		    if(d1[i]>d2[i])ma=d1[i];
		    else ma=d2[i];
		    if(d3[i]>ma)ma=d3[i];
            if(ma==d1[i])k1[++tot1]=i,ans+=d1[i];
            if(ma==d2[i]&&ma!=d1[i])k2[++tot2]=i,ans+=d2[i];
            if(ma==d3[i]&&ma!=d2[i]&&ma!=d1[i])k3[++tot3]=i,ans+=d3[i];
		}
		int o=0;
		if(tot1>n/2)o=1;
		if(tot2>n/2)o=2;
		if(tot3>n/2)o=3;
		if(o==0){
            cout<<ans<<endl;
            continue;
		}
		if(o==1){
            while(tot1){
                int x=k1[tot1];
                tot1--;
                int v=max(d2[x]-d1[x],d3[x]-d1[x]);
                k.push({v,x});
            }
		}
		if(o==2){
            while(tot2){
                int x=k2[tot2];
                tot2--;
                int v=max(d1[x]-d2[x],d3[x]-d2[x]);
                k.push({v,x});
            }
		}
		if(o==3){
            while(tot3){
                int x=k3[tot3];
                //cout<<x<<endl;
                tot3--;
                int v=max(d2[x]-d3[x],d1[x]-d3[x]);
                k.push({v,x});
            }
		}
		while(k.size()>n/2){
			//cout<<k.size();
            int vv=k.top().first;
            int xx=k.top().second;
            //cout<<vv<<" "<<xx<<" ";
            ans+=vv;
            k.pop();
		}
		cout<<ans<<endl;

	}
    return 0;
}
