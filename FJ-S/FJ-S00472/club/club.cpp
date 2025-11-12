#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int ret=0,sgn=0;
	char chr=getchar();
	while(!isdigit(chr)) sgn|=chr=='-',chr=getchar();
	while(isdigit(chr)) ret=ret*10+chr-'0',chr=getchar();
	return sgn ? -ret:ret;
}
int T;
bool cmp(int m,int n){
	return m>n;
}
void solve(){
	vector<int> a1;
	vector<int> a2;
	vector<int> a3;
	int n,ans=0;
	n=read();
	for(int i=0;i<n;i++){
		int a,b,c;
		a=read();
		b=read();
		c=read();
		//cout<<"1";
		if(a>=b&&a>=c){
			a1.push_back(min(a-b,a-c));
			ans+=a;
		}
		else if(b>=a&&b>=c){
			a2.push_back(min(b-a,b-c));
			ans+=b;
		} 
		else if(c>=a&&c>=b){
			a3.push_back(min(c-a,c-b));
			ans+=c;
		} 
		//cout<<ans<<" ";
	}
		if(a1.size()>n/2){
			sort(a1.begin(),a1.end());
			for(int i=0;i<a1.size()-n/2;i++){
				ans-=a1[i];
			}
		}
		if(a2.size()>n/2){
			sort(a2.begin(),a2.end());
			for(int i=0;i<a2.size()-n/2;i++){
				ans-=a2[i];
			}
		}
		if(a3.size()>n/2){
			sort(a3.begin(),a3.end());
			for(int i=0;i<a3.size()-n/2;i++){
				ans-=a3[i];
			}
		}
		cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(int t=0;t<T;t++) solve();
	return 0;
} 
