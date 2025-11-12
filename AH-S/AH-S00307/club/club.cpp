#include <bits/stdc++.h>
using namespace std;
int t;
struct P{
	int a;
	int b;
	int c;
	int d;
};
bool cmp(P x,P y){
	return x.d>y.d;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,k=0,l1=0,l2=0,l3=0;
		P v[100010];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			v[i].d=max({v[i].a,v[i].b,v[i].c});
			if(v[i].d==v[i].a)l1++;
			else if(v[i].d==v[i].b)l2++;
			else l3++;
			k+=v[i].d;
		}
		if(l1<=n/2&&l2<=n/2&&l3<=n/2){
			cout<<k<<endl;
			continue;
		}else{
			sort(v,v+n,cmp);
			for(int i=0;i<n;i++){
				if(v[i].d==v[i].a&&l1>n/2){
					v[i].d=max(v[i].b,v[i].c);
					if(v[i].d==v[i].b)l2++;
					if(v[i].d==v[i].c)l3++;
					l1--;
					k-=v[i].a-v[i].d;
				}else if(v[i].d==v[i].b&&l2>n/2){
					v[i].d=max(v[i].a,v[i].c);
					if(v[i].d==v[i].a)l1++;
					if(v[i].d==v[i].c)l3++;
					l2--;
					k-=v[i].b-v[i].d;
				}else{
					v[i].d=max(v[i].a,v[i].b);
					if(v[i].d==v[i].a)l1++;
					if(v[i].d==v[i].b)l2++;
					l3--;
					k-=v[i].c-v[i].d;
				}
				if(l1<=n/2&&l2<=n/2&&l3<=n/2){
					cout<<k<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
