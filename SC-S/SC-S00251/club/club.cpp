#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,T,tot=0,ans1=0,maxn=-1,ans2=0,ans3=0,tt=0,tt1=0;
int f1=1,f2=1;
struct node{
	int n1,n2,n3;
}a[N];

bool cmp(const node aa,const node bb){
	if(aa.n1!=bb.n1) return aa.n1>bb.n1;
	else if(aa.n2!=bb.n2) return aa.n2>bb.n2;
	else aa.n3>bb.n3;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	t=T;
	while(t--){
		f1=1;
		f2=1;
		ans1=0;
		ans2=0;
		ans3=0;
		maxn=-1;
		tot=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			tt+=a[i].n1+a[i].n2+a[i].n3;
			tt1+=a[i].n1;
			if(a[i].n3!=0) f2=0;
		}
		
		if(tt!=tt1) f1=0;
		int limitt=n/2;
		
		sort(a+1,a+n+1,cmp);
		
		if(tt==tt1){
			for(int i=1;i<=limitt;i++){
				tot+=a[i].n1;
			}
//			cout<<"ok"<<'\n';
		}
		
		else if(f2){
			for(int i=1;i<=n;i++){
				if(a[i].n1>a[i].n2){
					if(ans1+1<=limitt){
						ans1++;
						tot+=a[i].n1;
					}
					else if(ans2+1<=limitt){
						ans2++;
						tot+=a[i].n2;
					}
					else ans3++;
				}
				if(a[i].n2>=a[i].n1){
					if(ans2+1<=limitt){
						ans2++;
						tot+=a[i].n2;
					}
					else if(ans1+1<=limitt){
						ans1++;
						tot+=a[i].n1;
					}
					else ans3++;
				}
			}
//			cout<<"ok1"<<'\n';
		}
		
		else if(!f1&&!f2){
			for(int i=1;i<=n;i++){
				maxn=max(a[i].n1,a[i].n2);
				maxn=max(maxn,a[i].n3);
				if(maxn==a[i].n1){
					if(ans1+1<=limitt){
						ans1++;
						tot+=a[i].n1;
					}
					else if(ans2+1<=limitt&&a[i].n2>a[i].n3){
						ans2++;
						tot+=a[i].n2;
					}
					else {
						ans3++;
						tot+=a[i].n3;
					}
				}
				else if(maxn==a[i].n2){
					if(ans2+1<=limitt){
						ans2++;
						tot+=a[i].n2;
					}
					else if(ans1+1<=limitt&&a[i].n1>a[i].n3){
						ans1++;
						tot+=a[i].n1;
					}
					else {
						ans3++;
						tot+=a[i].n3;
					}
				}
				else if(maxn==a[i].n3){
					if(ans3+1<=limitt){
						ans3++;
						tot+=a[i].n3;
					}
					else if(ans1+1<=limitt&&a[i].n1>a[i].n2){
						ans1++;
						tot+=a[i].n1;
					}
					else {
						ans2++;
						tot+=a[i].n2;
					}
				}
			}
		}
		
		if(t!=T) cout<<tot<<'\n';
		else cout<<tot;
	}
	return 0;
}