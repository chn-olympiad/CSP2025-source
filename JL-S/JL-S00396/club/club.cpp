#include<bits/stdc++.h>
using namespace std;
#define int long long
#define elif else if
int n,t;
int *ans;
struct man{
	int d[4],tend;
};
bool cmp(man a,man b){
	if(a.tend!=b.tend) return a.tend<b.tend;
	elif(a.d[1]!=b.d[1]) return a.d[1]>b.d[1];
	elif(a.d[2]!=b.d[2]) return a.d[2]>b.d[2];
	else return a.d[3]>b.d[3];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	ans=new int[t+1];
	for(int _=1;_<=t;++_){
		man *a;
		cin>>n;
		a=new man[n+1];
		for(int i=1;i<=n;++i){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(max(a[i].d[1],max(a[i].d[2],a[i].d[3]))==a[i].d[1]){
				a[i].tend=1;
			}
			elif(max(a[i].d[1],max(a[i].d[2],a[i].d[3]))==a[i].d[2]){
				a[i].tend=2;
			}
			elif(max(a[i].d[1],max(a[i].d[2],a[i].d[3]))==a[i].d[3]){
				a[i].tend=3;
			}
		}
		sort(a+1,a+n+1,cmp);
		int sum=0,i=1;
		while(sum<=n/2 && a[i].tend==1){
			if(a[i].d[1]-max(a[i].d[2],a[i].d[3])<a[i].d[1]-a[i+1].d[1]){
				a[i].d[1]=-1;
				if(max(a[i].d[2],a[i].d[3])==a[i].d[2]){
					a[i].tend=2;
				}
				elif(max(a[i].d[2],a[i].d[3])==a[i].d[3]){
					a[i].tend=3;
				}
				++i;
			}
			else{
				ans[_]+=a[i].d[1];
				a[i].d[1]=a[i].d[2]=a[i].d[3]=-1;
				++sum;
				a[i].tend=4;
				++i;
			}
		}
		while(a[i].tend==1){
			a[i].d[1]=-1;
			if(max(a[i].d[2],a[i].d[3])==a[i].d[2]){
				a[i].tend=2;
			}
			elif(max(a[i].d[2],a[i].d[3])==a[i].d[3]){
				a[i].tend=3;
			}
			++i;
		}
		sort(a+1,a+n+1,cmp);
		sum=0;i=1;
		while(sum<=n/2 && a[i].tend==2){
			if(a[i].d[2]-a[i].d[3]<a[i].d[2]-a[i+1].d[2] && a[i+1].d[2]!=-1){
				a[i].d[2]=-1;
				a[i].tend=3;
				++i;
			}
			else{
				ans[_]+=a[i].d[2];
				a[i].d[1]=a[i].d[2]=a[i].d[3]=-1;
				++sum;
				a[i].tend=4;
				++i;
			}
		}
		while(a[i].tend==2){
			a[i].d[2]=-1;
			a[i].tend=3;
			++i;
		}
		sort(a+1,a+n+1,cmp);
		sum=0;i=1;
		while(sum<=n/2 && a[i].tend==3){
			ans[_]+=a[i].d[3];
			a[i].d[1]=a[i].d[2]=a[i].d[3]=-1;
			++sum;
			a[i].tend=4;
			++i;
		}
	}
	for(int _=1;_<=t;++_){
		cout<<ans[_]<<"\n";
    }
	return 0;
}
