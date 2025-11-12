#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
struct node{
	int num,sub;
}a[100010],b[100010],c[100010];
bool cmp(node x,node y){
	return x.num>y.num;
}
map<int,bool> m;
int t,n,li,f,s,l;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m.clear();
		ans=0,f=0,s=0,l=0;
		li=n/2;
		for(int i=1;i<=n;i++) m[i]=true;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].sub=i;
			b[i].sub=i;
			c[i].sub=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(m[a[i].sub] && f<li){
				ans+=a[i].num;
				f++;
				m[a[i].sub]=false;
			}
			if(m[b[i].sub] && s<li){
				ans+=b[i].num;
				s++;
				m[b[i].sub]=false;
			
			}
			if(m[c[i].sub] && l<li){
				ans+=c[i].sub;
				l++;
				m[c[i].sub]=false;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
	//dp不牢，下次再战吧
}
