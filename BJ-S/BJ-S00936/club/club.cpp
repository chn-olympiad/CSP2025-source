#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100010];
priority_queue<int,vector<int>,greater<int> > va,vb,vc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		while(va.size()) va.pop();
		while(vb.size()) vb.pop();
		while(vc.size()) vc.pop();
		int n,ans=0,A=0,B=0,C=0,f=0,s=0,t=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				va.push(min(a[i].a-a[i].b,a[i].a-a[i].c));
				A+=a[i].a;
				f++;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				vb.push(min(a[i].b-a[i].a,a[i].b-a[i].c));
				B+=a[i].b;
				s++;
			}
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
				vc.push(min(a[i].c-a[i].a,a[i].c-a[i].b));
				C+=a[i].c;
				t++;
			}
		}
		ans=A+B+C;
		if(f>=n/2){
			for(int i=1;i<=f-n/2;i++){
				ans-=va.top();
				va.pop();
			}
		}
		else if(s>=n/2){
			for(int i=1;i<=s-n/2;i++){
				ans-=vb.top();
				vb.pop();
			}
		}
		else if(t>=n/2){
			for(int i=1;i<=t-n/2;i++){
				ans-=vc.top();
				vc.pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}