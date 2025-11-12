#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,ans[6];
struct Person{
	int a;
	int b;
	int c;
};
bool cmp(Person x,Person y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c<y.c;
		}
		return x.b<y.b;
	}
	return x.a<y.a;
}
Person p[N];
bool per[N][4];
int people[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int t1=1;
	while(t1<=t){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		sort(p,p+n+1,cmp);
		for(int i=n;i>=1;i--){
			if(p[i].a>=p[i].b&&people[1]<n/2){
				per[i][1]==1;
				people[1]++;
			}
			else{
				per[i][2]==1;
				people[2]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(per[i][1]==1){
				ans[t1]+=p[i].a;
			}
			else if(per[i][2]==1){
				ans[t1]+=p[i].b;
			}
			else
				ans[t1]+=p[i].c;
		}
		t1++;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
