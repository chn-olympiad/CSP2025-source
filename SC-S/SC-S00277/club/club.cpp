#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,ti_min;
};
bool cmp(node a,node b){
	return a.ti_min<b.ti_min;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		vector<node> n1,n2,n3;
		int ans=0;
		int num;
		cin>>num;
		for(int i=1;i<=num;i++){
			int ax,bx,cx;
			cin>>ax>>bx>>cx;
			if(ax==max(ax,max(bx,cx))){
				node p;
				p.a=ax;
				p.ti_min=min(abs(ax-bx),abs(ax-cx));
				n1.push_back(p);
			}
			else if(bx==max(ax,max(bx,cx))){
				node p;
				p.a=bx;
				p.ti_min=min(abs(ax-bx),abs(bx-cx));
				n2.push_back(p);
			}
			else{
				node p;
				p.a=cx;
				p.ti_min=min(abs(cx-bx),abs(ax-cx));
				n3.push_back(p);
			}
		} 
		for(auto j:n1) ans+=j.a;
		for(auto j:n2) ans+=j.a;
		for(auto j:n3) ans+=j.a;
		if(n1.size()*2<=num&&n2.size()*2<=num&&n3.size()*2<=num){
			cout<<ans<<'\n';
			continue;
		}
		if(n1.size()*2>num){
			sort(n1.begin(),n1.end(),cmp);
			for(int i=0;i<ceil(n1.size()-num/2.0);i++){
				ans-=n1[i].ti_min;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n2.size()*2>num){
			sort(n2.begin(),n2.end(),cmp);
			for(int i=0;i<ceil(n2.size()-num/2.0);i++){
				ans-=n2[i].ti_min;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n3.size()*2>num){
			sort(n3.begin(),n3.end(),cmp);
			for(int i=0;i<ceil(n3.size()-num/2.0);i++){
				ans-=n3[i].ti_min;
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
} 