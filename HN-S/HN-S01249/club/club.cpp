#include<bits/stdc++.h>
using namespace std;
int t,n;
struct name{
	int a,b,c;
}a[100810];
struct node{
	int id,d,w;
};
vector<int>vt[4];
bool cmp1(int x,int y){
	return a[x].a<a[y].a;
}
bool cmp2(int x,int y){
	return a[x].b<a[y].b;
}
bool cmp3(int x,int y){
	return a[x].c<a[y].c;
}
bool cmp4(node x,node y){
	return x.d>y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		vt[1].clear();
		vt[2].clear();
		vt[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				vt[1].push_back(i);
			}
			if(a[i].b>a[i].a&&a[i].b>=a[i].c){
				vt[2].push_back(i);
			}
			if(a[i].c>a[i].a&&a[i].c>a[i].b){
				vt[3].push_back(i);
			}
		}
		sort(vt[1].begin(),vt[1].end(),cmp1);
		sort(vt[2].begin(),vt[2].end(),cmp2);
		sort(vt[3].begin(),vt[3].end(),cmp3);
		int ans=0;
		for(int i=1;i<=3;i++){
			if(vt[i].size()<=n/2){
				for(auto v:vt[i]){
					if(i==1)ans+=a[v].a;
					if(i==2)ans+=a[v].b;
					if(i==3)ans+=a[v].c;
				}
			}
			else{
				int sum=0; 
				for(auto v:vt[i]){//对于下标为1的人 
					if(i==1)sum+=a[v].a;
					if(i==2)sum+=a[v].b;
					if(i==3)sum+=a[v].c;
				}
				vector<node>haha;
				for(auto v:vt[i]){
					if(i==1){
						int w1=0,w2=0;
						if(n/2-vt[2].size()>=1){
							w1=max(w1,sum-a[v].a+a[v].b);
						}
						if(n/2-vt[3].size()>=1){
							w2=max(w2,sum-a[v].a+a[v].c);
						}
						if(w1>=w2){
							haha.push_back({v,w1,a[v].b});
							//cout<<w1<<" ";
						}
						if(w2>w1)haha.push_back({v,w2,a[v].c});
					}
					if(i==2){
						int w1=0,w2=0;
						if(n/2-vt[1].size()>=1){
							w1=max(w1,sum-a[v].b+a[v].a);
						}
						if(n/2-vt[3].size()>=1){
							w2=max(w2,sum-a[v].b+a[v].c);
						}
						if(w1>=w2)haha.push_back({v,w1,a[v].a});
						if(w2>w1)haha.push_back({v,w2,a[v].c});
					}
					if(i==3){
						int w1=0,w2=0;
						if(n/2-vt[2].size()>=1){
							w1=max(w1,sum-a[v].c+a[v].b);
						}
						if(n/2-vt[1].size()>=1){
							w2=max(w2,sum-a[v].c+a[v].a);
						}
						if(w1>=w2)haha.push_back({v,w1,a[v].b});
						if(w2>w1)haha.push_back({v,w2,a[v].a});
					}
				}
				sort(haha.begin(),haha.end(),cmp4);
				for(int j=0;j<vt[i].size()-n/2;j++){
					node v=haha[j];
					if(i==1){
						sum=sum-a[v.id].a+v.w;
					}
					if(i==2){
						sum=sum-a[v.id].b+v.w;
					}
					if(i==3)sum=sum-a[v.id].c+v.w;
				}
				ans+=sum;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
