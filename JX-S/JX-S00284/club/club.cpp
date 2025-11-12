#include<bits/stdc++.h>
using namespace std;
int t,b[5]={0,0,0,0,0},maxa,sum,ans,n;
struct node{
	int s[4],d1,d2,d3;
};
bool cmp(node q,node w){
	if(q.s[q.d1]!=w.s[w.d1]) return q.s[q.d1]>w.s[w.d1];
	else if(q.s[q.d2]!=w.s[w.d2]) return q.s[q.d2]>w.s[w.d2];
	else return q.s[q.d3]>w.s[w.d3];
}
node a[100005];
int dg(int i,int p){
	if(i==1){
		b[0]=b[1]=b[2]=b[3]=b[4]=0;
		b[p]++;
		sum+=a[i].s[p];
	}
	else{
		if(b[a[i].d1]<maxa){
			b[a[i].d1]++;
			sum+=a[i].s[a[i].d1];
		}
		else if(b[a[i].d2]<maxa){
			b[a[i].d2]++;
			sum+=a[i].s[a[i].d2];
		}
		else if(b[a[i].d3]<maxa){
			b[a[i].d3]++;
			sum+=a[i].s[a[i].d3];
		}
	}
	if(i==n){
		ans=max(ans,sum);
		sum=0;
		return ans;
	}
	else{
		return dg(i+1,1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		ans=0;
		cin>>n;
		maxa=n/2;
		b[0]=b[1]=b[2]=b[3]=b[4]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			if(a[i].s[1]>=a[i].s[2]&&a[i].s[2]>=a[i].s[3]){
				a[i].d1=1;
				a[i].d2=2;
				a[i].d3=3;
			}
			else if(a[i].s[1]>=a[i].s[3]&&a[i].s[3]>=a[i].s[2]){
				a[i].d1=1;
				a[i].d2=3;
				a[i].d3=2;
			}
			else if(a[i].s[2]>=a[i].s[3]&&a[i].s[3]>=a[i].s[1]){
				a[i].d1=2;
				a[i].d2=3;
				a[i].d3=1;
			}
			else if(a[i].s[2]>=a[i].s[1]&&a[i].s[1]>=a[i].s[3]){
				a[i].d1=2;
				a[i].d2=1;
				a[i].d3=3;
			}
			else if(a[i].s[3]>=a[i].s[1]&&a[i].s[1]>=a[i].s[2]){
				a[i].d1=3;
				a[i].d2=1;
				a[i].d3=2;
			}
			else if(a[i].s[3]>=a[i].s[2]&&a[i].s[2]>=a[i].s[1]){
				a[i].d1=3;
				a[i].d2=2;
				a[i].d3=1;
			}
		}
		sort(a+1,a+1+n,cmp);
		
		for(int i=1;i<=3;i++){
			dg(1,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
