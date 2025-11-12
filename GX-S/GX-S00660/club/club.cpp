#include<bits/stdc++.h>
using namespace std;
int kc[5];
long long sum;
struct node{
	long long a,b,c,pos,maxn,post;
}k[100005];
bool cmp(node x,node y){
	return x.maxn>y.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		kc[1]=kc[2]=kc[3]=0;sum=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>k[i].a>>k[i].b>>k[i].c;
			k[i].maxn=max(k[i].a,max(k[i].b,k[i].c));
			if(k[i].maxn==k[i].a) k[i].pos=1;
			else if(k[i].maxn==k[i].b) k[i].pos=2;
			else k[i].pos=3;
			
		}
		sort(k+1,k+n+1,cmp);
		//for(int i=1;i<=n;i++) cout<<k[i].a<<" "<<k[i].b<<" "<<k[i].c<<" "<<k[i].pos<<endl;
		for(int i=1;i<=n;i++)
		{
			if(k[i].pos==k[i+1].pos&&kc[k[i].pos]+2>(n/2)) {		
				int max1=-10,max2=-10,pos1,pos2;
				if(k[i].pos==1){
					if(k[i].b>k[i].c){ pos1=2;max1=k[i].b;}
					else { pos1=3;max1=k[i].c;}
					if(k[1+i].b>k[i+1].c) { pos2=2;max2=k[i+1].b;}
					else { pos2=3;max2=k[i+1].c;}	
				}
				if(k[i].pos==2){
					if(k[i].a>k[i].c){ pos1=1;max1=k[i].a;}
					else { pos1=3;max1=k[i].c;}
					if(k[1+i].a>k[i+1].c) { pos2=2;max2=k[i+1].a;}
					else { pos2=3;max2=k[i+1].c;}
				}
				if(k[i].pos==3){
					if(k[i].a>k[i].b){ pos1=1;max1=k[i].a;}
					else { pos1=2;max1=k[i].b;}
					if(k[1+i].a>k[i+1].b) { pos2=1;max2=k[i+1].a;}
					else { pos2=2;max2=k[i+1].b;}
				}
				if(max1+k[i+1].maxn>max2+k[i].maxn) {sum+=max1+k[i+1].maxn;}
				else sum+=max2+k[i].maxn;
				kc[pos1]++;kc[pos2]++;
				i+=2;
			}
			else if(k[i].pos==1) {
				if(kc[1]<=n/2){sum+=k[i].maxn;kc[1]++;}
				else {
					if(k[i].b>k[i].c&&kc[2]<=n/2){sum+=k[i].b;kc[2]++;}
					else if(k[i].b<k[i].c&&kc[3]<=n/2){sum+=k[i].c;kc[3]++;}
				}
			}
			else if(k[i].pos==2) {
				if(kc[2]<=n/2){sum+=k[i].maxn;kc[2]++;}
				else {
					if(k[i].a>k[i].c&&kc[1]<=n/2){sum+=k[i].a;kc[1]++;}
					else if(k[i].a<k[i].c&&kc[3]<=n/2){sum+=k[i].c;kc[3]++;}
				}
			}
			else if(k[i].pos==3) {
				if(kc[3]<=n/2){sum+=k[i].maxn;kc[3]++;}
				else {
					if(k[i].b>k[i].a&&kc[2]<=n/2){sum+=k[i].b;kc[2]++;}
					else if(k[i].b<k[i].a&&kc[1]<=n/2){sum+=k[i].a;kc[1]++;}
				}
			}
		}
		
		cout<<sum<<endl;
	}
	return 0;
}
