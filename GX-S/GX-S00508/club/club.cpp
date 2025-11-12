#include<bits/stdc++.h>
using namespace std;
struct chengyuan{
	int a,b,temp;
}p[100001];
int t,n,ta,tb,sum=0;
int va[50010],vb[50010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].temp;
			p[i].temp=abs(p[i].a-p[i].b);
			if(p[i].a>=p[i].b){
				va[++ta]=i;
				if(ta>n/2){
					int min1=0x3f3f3f3f,pos;
					for(int j=1;j<=ta;j++)
						if(p[va[j]].temp<min1){
							min1=p[va[j]].temp;
							pos=j;
						}
					vb[++tb]=va[pos];
					va[pos]=0;
					sort(va+1,va+ta+1,greater<int>());
					ta--;
				}
			}else{
				vb[++tb]=i;
				if(tb>n/2){
					int min1=0x3f3f3f3f,pos;
					for(int j=1;j<=tb;j++)
						if(p[vb[j]].temp<min1){
							min1=p[vb[j]].temp;
							pos=j;
						}
					va[++ta]=vb[pos];
					vb[pos]=0;
					sort(vb+1,vb+tb+1,greater<int>());
					tb--;
				}
			}
		}
	}
	for(int i=1;i<=ta;i++)
		sum+=p[va[i]].a;
	for(int i=1;i<=tb;i++)
		sum+=p[vb[i]].b;
	cout<<sum<<endl;
	return 0;
}
