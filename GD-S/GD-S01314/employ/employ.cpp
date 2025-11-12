#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll N=505,P=998244353;
int n,m;
char ch;
bool s[N];
pair<int,int> c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>ch;
		s[i]= ch=='0';
	}
	for(int i=1;i<=n;++i){
		cin>>c[i].second;
		c[i].first=i;
	}
	if(n<=14){
		ll ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(s[i] or cnt>=c[i].second){
					++cnt;
				}
			}
			if(n-cnt>=m) ++ans;
		}while(next_permutation(c+1,c+1+n));
		cout<<ans%P<<endl;
	}else{
		ll ans=1;
		for(int i=2;i<=n;++i){
			ans=(ans*i)%P;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

