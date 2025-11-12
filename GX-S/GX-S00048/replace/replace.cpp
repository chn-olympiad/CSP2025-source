#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}a[2000005];
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=m;i++){
		string b,c;
		int ans=0;
		cin>>b>>c;
		for(int l=1;l<=n;l++){
			int w=0;
			node t=a[l];
			string xx=t.s1,yy=t.s2,aa=b;
			int p=aa.find(xx);
			int r=aa.find(yy);
			if(p!=-1){
				for(int f=p,e=0;f<p+yy.size();f++,e++){
					aa[f]=yy[e];
				}
			}		
			if(aa==c) w=1;
			if(r!=-1){
				for(int f=r,e=0;f<r+xx.size();f++,e++){
					aa[f]=xx[e];
				}
			}			
			if(aa==c) w=1;
			if(w==1) ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
