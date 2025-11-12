#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
struct Node{
	int x,y,z,id;
}a[100010];
ull n;
long long ans=-1;
void f(string s,ull at,ull bt,ull ct){
	if(at>n/2||bt>n/2||ct>n/2)return;
	if(s.size()==n){
		long long sum=0;
		for(ull i=0;i<n;i++){
			if(s[i]=='x')sum+=a[i+1].x;
			else if(s[i]=='y')sum+=a[i+1].y;
			else sum+=a[i+1].z;
		}
		ans=max(ans,sum);
		return;
	}
	f(s+'x',at+1,bt,ct);
	f(s+'y',at,bt+1,ct);
	f(s+'z',at,bt,ct+1);
	return;
}
bool cmp(Node a,Node b){
	if(a.x!=b.x)return a.x>b.x;
	else return a.id<b.id;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		ull spa=0;
		cin>>n;
		for(ull i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;
			if(a[i].y==0&&a[i].z==0)spa++;
		}
		if(spa==n){
			sort(a+1,a+n+1,cmp);
			ull fake_ans=0;
			for(ull i=1;i<=n/2;i++)fake_ans+=a[i].x;
			cout<<fake_ans<<endl;
		}else{
			f("",0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
