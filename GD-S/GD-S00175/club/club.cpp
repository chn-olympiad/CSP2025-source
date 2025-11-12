#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int id,w; 
};
node v_1[N],v_2[N],v_3[N];
node aff[N];
int t;
bool cmp(node a,node b){
	return a.w<b.w;
}
int a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;cin>>n;
		int cnt_1=0,cnt_2=0,cnt_3=0;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i] && a[i]>=c[i])v_1[++cnt_1]={i,a[i]};
			else if(b[i]>=a[i] && b[i]>=c[i])v_2[++cnt_2]={i,b[i]};
			else v_3[++cnt_3]={i,c[i]};
		}
		if(cnt_1>(n/2)){
			for(int i=1;i<=cnt_1;i++){
				int k=v_1[i].id;
				aff[i]={i,a[k]-max(b[k],c[k])};
			}
			sort(aff+1,aff+cnt_1+1,cmp);
			for(int i=1;i<=cnt_1-(n/2);i++){
				v_1[aff[i].id].w=0;
				int k=v_1[aff[i].id].id;
				if(b[k]>c[k])v_2[++cnt_2]={k,b[k]};
				else v_3[++cnt_3]={k,c[k]}; 
			}
		}
		else if(cnt_2>(n/2)){
			for(int i=1;i<=cnt_2;i++){
				int k=v_2[i].id;
				aff[i]={i,b[k]-max(a[k],c[k])};
			}
			sort(aff+1,aff+cnt_2+1,cmp);
			for(int i=1;i<=cnt_2-(n/2);i++){
				v_2[aff[i].id].w=0;
				int k=v_2[aff[i].id].id;
				if(a[k]>c[k])v_1[++cnt_1]={k,a[k]};
				else v_3[++cnt_3]={k,c[k]}; 
			}
		}
		else{
			for(int i=1;i<=cnt_3;i++){
				int k=v_3[i].id;
				aff[i]={i,c[k]-max(b[k],a[k])};
			}
			sort(aff+1,aff+cnt_3+1,cmp);
			for(int i=1;i<=cnt_3-(n/2);i++){
				v_3[aff[i].id].w=0;
				int k=v_3[aff[i].id].id;
				if(b[k]>a[k])v_2[++cnt_2]={k,b[k]};
				else v_1[++cnt_1]={k,a[k]}; 
			}
		}
		long long ans=0;
		for(int i=1;i<=cnt_1;i++)ans+=v_1[i].w;
		for(int i=1;i<=cnt_2;i++)ans+=v_2[i].w;
		for(int i=1;i<=cnt_3;i++)ans+=v_3[i].w;
		cout<<ans<<endl;
	}
	return 0;
}
