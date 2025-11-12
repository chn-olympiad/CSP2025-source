#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nd{
	int a,b,c;
}t[100010],re[100010];
int n,ans;
void cl(){
	for(int i=0;i<=n+5;i++){
		t[i]=re[i]=nd();
	}
	n=ans=0;
}
void rek(){
	for(int i=1;i<=n;i++){
		re[i]={re[i].b,re[i].c,re[i].a};
	}
	for(int i=1;i<=n;i++){
		t[i]=re[i];
	}
}
void stc(){
	int ca=0,cb=0,cc=0,res=0;
	for(int i=1;i<=n;i++){
		if(t[i].a>=t[i].b&&t[i].a>=t[i].c){
			ca++;
			res+=t[i].a;
		}
		else if(t[i].b>=t[i].a&&t[i].b>=t[i].c){
			cb++;
			res+=t[i].b;
		}
		else{
			cc++;
			res+=t[i].c;
		}
	}
	if(max({ca,cb,cc})<=n/2){
		ans=max(ans,res);
	}
}
void sol(){
	int res=0;
	for(int i=1;i<=n;i++){
		res+=t[i].a;
		t[i].b-=t[i].a;
		t[i].c-=t[i].a;
	}
	vector<int> s;
	for(int i=1;i<=n;i++){
		s.push_back(max(t[i].b,t[i].c));
	}
	sort(s.begin(),s.end());
	for(int i=1;i<=n/2;i++){
		int u=s.back();
		s.pop_back();
		res+=u;
	}
	ans=max(ans,res);
} 
void catt(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].b>>t[i].c;
		re[i]=t[i];
	}
	stc();
	sol();
	for(int l=1;l<=2;l++){
		rek();
		sol();
	}
	cout<<ans<<"\n";
	cl();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int ct;
	cin>>ct;
	while(ct--){
		catt();
	}
}
