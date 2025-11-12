#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ac{
	int x,y,z;
}a[100005];
ll n,T,choice[100005],cha[100005],t1,t2,t3,ans,sortc[100005],scnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int I=1;I<=T;I++){
		memset(sortc,0,sizeof(sortc));
		scnt=0;
		ans=0;
		t1=0,t2=0,t3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)choice[i]=1,cha[i]=a[i].x-max(a[i].y,a[i].z),t1++;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)choice[i]=2,cha[i]=a[i].y-max(a[i].x,a[i].z),t2++;
			else choice[i]=3,cha[i]=a[i].z-max(a[i].x,a[i].y),t3++;
		}
		for(int i=1;i<=n;i++){
			if(choice[i]==1)ans+=a[i].x;
			else if(choice[i]==2)ans+=a[i].y;
			else ans+=a[i].z;
		}
		if(max(t1,max(t2,t3))>n/2){
			if(t1>t2+t3){
				for(int i=1;i<=n;i++)
					if(choice[i]==1)sortc[++scnt]=cha[i];
				sort(sortc+1,sortc+1+scnt);
				scnt-=(n/2);
				for(int i=1;i<=scnt;i++)ans-=sortc[i];
			}else if(t2>t1+t3){
				for(int i=1;i<=n;i++)
					if(choice[i]==2)sortc[++scnt]=cha[i];
				sort(sortc+1,sortc+1+scnt);
				scnt-=(n/2);
				for(int i=1;i<=scnt;i++)ans-=sortc[i];
			}else{
				for(int i=1;i<=n;i++)
					if(choice[i]==3)sortc[++scnt]=cha[i];
				sort(sortc+1,sortc+1+scnt);
				scnt-=(n/2);
				for(int i=1;i<=scnt;i++)ans-=sortc[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
