#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
}p[100005];
struct node1{
	int m,k;
}x[100005],y[100005],z[100005];
bool cmp1(node1 a1,node1 b1);
bool cmp2(node1 a1,node1 b1);
bool cmp3(node1 a1,node1 b1);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>t;
	int ans1,ans2,ans3;
	while(t--){
		cin>>n;
		ans1=0,ans2=0,ans3=0;
		memset(x,-1,sizeof(x));
		memset(y,-1,sizeof(y));
		memset(z,-1,sizeof(z));
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			int k=max(p[i].a,max(p[i].b,p[i].c));
			if(k==p[i].a){
				x[++ans1].m=p[i].a;
				x[ans1].k=i;
			}
			else if(k==p[i].b){
				y[++ans2].m=p[i].b;
				y[ans2].k=i;
			}
			else if(k==p[i].c){
				z[++ans3].m=p[i].c;
				z[ans3].k=i;
			}
		}
		if(ans1>n/2){
			sort(x+1,x+1+ans1,cmp1);
			int temp=ans1;
			for(int i=1;i<=temp&&ans1>n/2;i++){
				if(p[x[i].k].b>=p[x[i].k].c){
					y[++ans2].m=p[x[i].k].b;
					y[ans2].k=x[i].k;
					x[i].k=-1;
					ans1--;
				}
				else{
					z[++ans3].m=p[x[i].k].c;
					z[ans3].k=x[i].k;
					x[i].k=-1;
					ans1--;
				}
			}
		}
		if(ans2>n/2){
			sort(y+1,y+1+ans2,cmp2);
			int temp=ans2;
			for(int i=1;i<=temp&&ans2>n/2;i++,ans2--){
				if(p[y[i].k].a>=p[y[i].k].c){
					x[++ans1].m=p[y[i].k].a;
					x[ans1].k=y[i].k;
					y[i].k=-1;
				}
				else{
					z[++ans3].m=p[y[i].k].c;
					z[ans3].k=y[i].k;
					y[i].k=-1;
				}
//				cout<<ans2<<" ";
			}
//			cout<<endl;
		}
		if(ans3>n/2){
			sort(z+1,z+1+ans3,cmp3);
			int temp=ans3;
			for(int i=1;i<=temp&&ans3>n/2;i++){
				if(p[z[i].k].b>=p[z[i].k].a){
					y[++ans2].k=p[z[i].k].b;
					y[ans2].m=z[i].k;
					z[i].k=-1;
					ans3--;
				}
				else{
					x[++ans1].m=p[z[i].k].c;
					x[ans1].k=z[i].k;
					z[i].k=-1;
					ans3--;
				}
			}
		}
		int cnt=0;
//		cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
		for(int i=1;i<=n;i++){
			if(x[i].k!=-1&&x[i].m!=-1){
				
				cnt+=x[i].m;
			}
//			cout<<x[i].m<<" "<<x[i].k<<endl;
		}
		for(int i=1;i<=n;i++){
			if(y[i].k!=-1&&y[i].m!=-1){
				
				cnt+=y[i].m;
			}
//			cout<<y[i].m<<" "<<y[i].k<<endl;
		}
		for(int i=1;i<=n;i++){
			if(z[i].k!=1&&z[i].m!=-1){
				
				cnt+=z[i].m;
			}
//			cout<<z[i].m<<" "<<z[i].k<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
bool cmp1(node1 a1,node1 b1){
	if(max(p[a1.k].b,p[a1.k].c)==max(p[b1.k].b,p[b1.k].c)) return a1.m<b1.m;
	return max(p[a1.k].b,p[a1.k].c)>max(p[b1.k].b,p[b1.k].c);
}
bool cmp2(node1 a1,node1 b1){
	if(max(p[a1.k].a,p[a1.k].c)==max(p[b1.k].a,p[b1.k].c)) return a1.m<b1.m;
	return max(p[a1.k].a,p[a1.k].c)>max(p[b1.k].a,p[b1.k].c);
}
bool cmp3(node1 a1,node1 b1){
	if(max(p[a1.k].a,p[a1.k].b)==max(p[b1.k].a,p[b1.k].b)) return a1.m<b1.m;
	return max(p[a1.k].a,p[a1.k].b)>max(p[b1.k].a,p[b1.k].b);
}
