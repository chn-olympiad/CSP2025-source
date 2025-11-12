#include <bits/stdc++.h>
using namespace std;
int n,t,s[5],ans=0;
struct node{
	int maxx,maxxid,dr,drid,mdc,f,s,t;
}a[100005];
bool cmp(node x,node y){
	return x.maxx>y.maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			if(a[i].f>=a[i].s&&a[i].f>=a[i].t){
				a[i].maxx=a[i].f;
				a[i].maxxid=1;
				if(a[i].s>=a[i].t){
					a[i].dr=a[i].s;
					a[i].drid=2;
				}
				else{
					a[i].dr=a[i].t;
					a[i].drid=3;
				}
				a[i].mdc=a[i].maxx-a[i].dr;
			}
			else if(a[i].s>=a[i].f&&a[i].s>=a[i].t){
				a[i].maxx=a[i].s;
				a[i].maxxid=2;
				if(a[i].f>=a[i].t){
					a[i].dr=a[i].f;
					a[i].drid=1;
				}
				else{
					a[i].dr=a[i].t;
					a[i].drid=3;
				}
				a[i].mdc=a[i].maxx-a[i].dr;
			}
			else if(a[i].t>=a[i].f&&a[i].t>=a[i].s){
				a[i].maxx=a[i].t;
				a[i].maxxid=3;
				if(a[i].f>=a[i].s){
					a[i].dr=a[i].f;
					a[i].drid=1;
				}
				else{
					a[i].dr=a[i].s;
					a[i].drid=2;
				}
				a[i].mdc=a[i].maxx-a[i].dr;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[j].mdc<a[i].mdc){
					s[a[j].maxxid]--;
					s[a[j].drid]++;
					ans-=a[j].mdc;
					break;
				}
			}
			if(s[a[i].maxxid]>=n/2){
				ans+=a[i].dr;
				continue;
			}
			ans+=a[i].maxx;
			s[a[i].maxxid]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
