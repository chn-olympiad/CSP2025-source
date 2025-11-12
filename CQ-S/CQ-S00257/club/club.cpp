#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int xx,yy,zz;
	int mx,md,mn,mxid,mnid,mdid;//mx:最大  mn:最小
}a[N];
void js(int i,int a1,int b1,int c1){
	if(a1>b1){	//mxid:最大数的id,mnid:最小数的id a1,b2,c3	
		if(b1>c1){
			a[i].mx=a1;
			a[i].mxid=1;
			a[i].mn=c1;
			a[i].mnid=3;
			a[i].md=b1;
			a[i].mdid=2;
			return ;
		}
		else{
			if(a1>c1){
				a[i].mx=a1;
				a[i].mxid=1;
				a[i].mn=b1;
				a[i].mnid=2;
				a[i].md=c1;
				a[i].mdid=3;
				return ;
			}
			else{
				a[i].mx=c1;
				a[i].mxid=3;
				a[i].mn=b1;
				a[i].mnid=2;
				a[i].md=a1;
				a[i].mdid=1;
				return ;
			}
		}
	}
	else{
		if(a1>c1){
			a[i].mx=b1;
			a[i].mxid=2;
			a[i].mn=c1;
			a[i].mnid=3;
			a[i].md=a1;
			a[i].mdid=1;
			return ;
		}
		else{
			if(b1>c1){
				a[i].mx=b1;
				a[i].mxid=2;
				a[i].mn=a1;
				a[i].mnid=1;
				a[i].md=c1;
				a[i].mdid=3;
				return ;
			}
			else{
				a[i].mx=c1;
				a[i].mxid=3;
				a[i].mn=a1;
				a[i].mnid=1;
				a[i].md=b1;
				a[i].mdid=2;
				return ;
			}
		}
	}
}
bool cmp(node aa,node bb){
	if((aa.mx-aa.mn)!=(bb.mx-bb.mn)){
		return (aa.mx-aa.mn)>(bb.mx-bb.mn);
	}
	else{
		if(aa.md!=bb.md){
			return aa.md<bb.md;
		}
		return aa.mn>bb.mn;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].xx>>a[i].yy>>a[i].zz;
			js(i,a[i].xx,a[i].yy,a[i].zz);
		}		
		sort(a+1,a+n+1,cmp);
		int ans=0; 
		int temp=n/2;
		int rs[4]={0,temp,temp,temp};
		for(int i=1;i<=n;i++){
			if(rs[a[i].mxid]>0){
				rs[a[i].mxid]--;
				ans+=a[i].mx;
			}
			else{
				if(rs[a[i].mdid]>0){
					rs[a[i].mdid]--;
					ans+=a[i].md;
				}
				else if(rs[a[i].mnid]>0){
					rs[a[i].mnid]--;
					ans+=a[i].mn;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
