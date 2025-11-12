#include<bits/stdc++.h> 
using namespace std;
const int maxn=1e5+5;
struct node{
	int a,b,c,ch,ch1,bb,bb1;
}a[maxn];
int n;
bool cmp(node x,node y){
	if(x.ch==y.ch){
		return x.ch1>y.ch1;
	}
	return x.ch>y.ch;
}
void f(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
			a[i].bb=1;
			a[i].ch=a[i].a-max(a[i].b,a[i].c);
			a[i].ch1=abs(a[i].b-a[i].c);
			if(a[i].b>a[i].c)a[i].bb1=2; 
			else a[i].bb1=3;
		}
		else if(a[i].b>=a[i].c&&a[i].b>=a[i].a){
			a[i].bb=2;
			a[i].ch=a[i].b-max(a[i].a,a[i].c);
			a[i].ch1=abs(a[i].a-a[i].c);
			if(a[i].a>a[i].c)a[i].bb1=1; 
			else a[i].bb1=3;
		}
		else{
			a[i].bb=3;
			a[i].ch=a[i].c-max(a[i].a,a[i].b);
			a[i].ch1=abs(a[i].b-a[i].a);
			if(a[i].b>a[i].a)a[i].bb1=2; 
			else a[i].bb1=1;
		}
	}
	sort(a+1,a+1+n,cmp);
	int c[10]={};
	for(int i=1;i<=n;i++){
		if(c[a[i].bb]<n/2){
			ans+=max({a[i].a,a[i].b,a[i].c});
			c[a[i].bb]++;
		}
		else{
			if(a[i].bb1==1){
				ans+=a[i].a;
				c[1]++;
			}
			else if(a[i].bb1==2){
				ans+=a[i].b;
				c[2]++;
			}
			else{
				ans+=a[i].c;
				c[3]++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		f();
	}
}
