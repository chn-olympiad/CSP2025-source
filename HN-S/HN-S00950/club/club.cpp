#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T;
struct ob{
	int a,b,c;
	ob(int q,int w,int e):a(q),b(w),c(e){}
};
bool cmp(const ob x,const ob y){
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,t1=0,t2=0,t3=0,ans=0;
		vector<ob>s;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			s.push_back(ob(x,y,z));
		}
		sort(s.begin(),s.end(),cmp);
//		for(int i=0;i<n;i++){
//			cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<" ";
//		}
		for(int i=0;i<n;i++){
			if(s[i].a>=s[i].b&&s[i].b>=s[i].c){
				if(t1+1<=n/2){
					ans+=s[i].a;
					//cout<<s[i].a;
					t1++;
				}else if(t2+1<=n/2){
					ans+=s[i].b;
					//cout<<s[i].b;
					t2++;
				}else{
					ans+=s[i].c;
					//cout<<s[i].c;
					t3++;
				}
			}else if(s[i].a>=s[i].c&&s[i].c>=s[i].b){
				if(t1+1<=n/2){
					ans+=s[i].a;
					//cout<<s[i].a;
					t1++;
				}else if(t3+1<=n/2){
					ans+=s[i].c;
					//cout<<s[i].c;
					t3++;
				}else{
					ans+=s[i].b;
					//cout<<s[i].b;
					t2++;
				}
			}else if(s[i].b>=s[i].c&&s[i].c>=s[i].a){
				if(t2+1<=n/2){
					ans+=s[i].b;
					//cout<<s[i].b;
					t2++;
				}else if(t3+1<=n/2){
					ans+=s[i].c;
					//cout<<s[i].c;
					t3++;
				}else{
					ans+=s[i].a;
					//cout<<s[i].a;
					t1++;
				}
			}else if(s[i].b>=s[i].a&&s[i].a>=s[i].c){
				if(t2+1<=n/2){
					ans+=s[i].b;
					//cout<<s[i].b;
					t2++;
				}else if(t1+1<=n/2){
					ans+=s[i].a;
					cout<<s[i].a;
					t1++;
				}else{
					ans+=s[i].c;
					//cout<<s[i].c;
					t3++;
				}
			}else if(s[i].c>=s[i].b&&s[i].b>=s[i].a){
				if(t3+1<=n/2){
					ans+=s[i].c;
					//cout<<s[i].c;
					t3++;
				}else if(t2+1<=n/2){
					ans+=s[i].b;
					//cout<<s[i].b;
					t2++;
				}else{
					ans+=s[i].a;
					//cout<<s[i].a;
					t1++;
				}
			}else if(s[i].c>=s[i].a&&s[i].a>=s[i].b){
				if(t3+1<=n/2){
					ans+=s[i].c;
					//cout<<s[i].c;
					t3++;
				}else if(t1+1<=n/2){
					ans+=s[i].a;
				//	cout<<s[i].a;
					t1++;
				}else{
					ans+=s[i].b;
					//cout<<s[i].b;
					t2++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

 
