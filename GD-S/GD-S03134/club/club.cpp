#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=1e5+10;
int n,t;
struct people{
	int v;
	int a[4];
	int maxv(){
		return max(a[1],max(a[2],a[3]));
	}
	int maxi;
	
};
bool vis[N];
int man[4];
people p[N];
int hbdj[N];

bool cmp(people p1,people p2){
	return p1.maxv()>p2.maxv();
}

bool cmp2(int a1,int a2){
	return hbdj[a1]<hbdj[a2];
}

void solve(){
	cin>>n;
	int n1[N];
	int n2[N];
	int n3[N];
	
	int tmp[4];
	memset(hbdj,0,sizeof(hbdj));
	memset(vis,0,sizeof(vis));
	memset(man,0,sizeof(man));
	memset(tmp,0,sizeof(tmp));
	memset(n1,0,sizeof(n1));
	memset(n2,0,sizeof(n2));
	memset(n3,0,sizeof(n3));
	long long ans=0;
	int tb=0;
	int cnt1=0,cnt2=0,cnt3=0;
	
	for(int i=1;i<=n;i++){
		cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
		tmp[1]=p[i].a[1];
		tmp[2]=p[i].a[2];
		tmp[3]=p[i].a[3];
		if (tmp[1]==p[i].maxv()){
			p[i].maxi=1;
		}
		else if (tmp[2]==p[i].maxv()){
			p[i].maxi=2;
		}
		else{
			p[i].maxi=3;
		}
		//cout<<"a:"<<p[i].a<<"b:"<<p[i].b<<"v:"<<p[i].v<<endl;
		sort(tmp+1,tmp+4);
		hbdj[i]=tmp[3]-tmp[2];
		
		
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		man[p[i].maxi]+=1;
		vis[i]=1;
		ans+=p[i].maxv();
		if (p[i].maxi==1){
			n1[man[1]]=i;
		}
		else if (p[i].maxi==2){
			n2[man[2]]=i;
		}
		else n3[man[3]]=i;
	}
	//cout<<man[1]<<' '<<man[2]<<' '<<man[3]<<endl;
	//cout<<n/2<<endl;
	if (man[1]>n/2){		
		sort(n1+1,n1+1+man[1],cmp2);
		for(int i=1;i<=man[1]-(n/2);i++){
			ans-=hbdj[n1[i]];
		}
	}
	else if (man[2]>n/2){
		
		sort(n2+1,n2+1+man[2],cmp2);
		for(int i=1;i<=man[2]-(n/2);i++){
			ans-=hbdj[n2[i]];
		}
	}
	else{
		sort(n3+1,n3+1+man[3],cmp2);
		for(int i=1;i<=man[3]-(n/2);i++){
			ans-=hbdj[n3[i]];
		}
	}
	
	
	cout<<ans<<endl;
	
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
