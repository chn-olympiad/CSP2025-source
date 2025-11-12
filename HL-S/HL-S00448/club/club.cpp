#include<bits/stdc++.h>

using namespace std;


struct node{
	int a,b,c,pre;
}t[100005];
long long ans,T,n,num[5];

bool cmp(node x,node y){
	return x.pre>y.pre;
}

long long mid(int a,int b,int c){
	if(a<=b&&b<=c) return b;
	if(b<=a&&a<=c) return a;
	if(a<=c&&c<=b) return c;
	if(b<=c&&c<=a) return c;
	if(c<=b&&b<=a) return b;
	if(c<=a&&a<=b) return a;
}

long long maxs(int a,int b,int c){
	if(a>=b&&a>=c){num[1]++;return 1;}
	if(b>=a&&b>=c){num[2]++;return 2;}
	if(c>=a&&c>=b){num[3]++;return 3;}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		num[1]=0;
		num[2]=0;
		num[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			t[i].pre=max(max(t[i].a,t[i].b),t[i].c)-mid(t[i].a,t[i].b,t[i].c);
		}
//		for(int i=1;i<=n;i++){
//			cout<<t[i].cha<<' ';
//		}
		sort(t+1,t+n+1,cmp);
		for(int i=1;i<=n;i++){
			int ret=maxs(t[i].a,t[i].b,t[i].c);
			if(num[ret]<=n/2){
				if(ret==1) ans+=t[i].a;
				if(ret==2) ans+=t[i].b;
				if(ret==3) ans+=t[i].c;
			}else{
				ans+=mid(t[i].a,t[i].b,t[i].c);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
