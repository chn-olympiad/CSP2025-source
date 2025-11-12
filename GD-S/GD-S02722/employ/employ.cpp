#include<bits/stdc++.h>
#define TIMU (string)"employ"
#define ll long long
#define ull unsigned long long
using namespace std;
vector<int> dif(555,0);
vector<int> c(555,0);
int n,m;
const ll mod = 998244353;
int jie_chen(const int n){
	ll r = 1;
	for(ll i = 1;i<=n;i++){
		r *= i;
		r = r%mod;
	}
	return r;
}
int jie_chen1(const int a,const int b){
	ll r = 1;
	for(ll i = a;i<=b;i++){
		r *= i;
		r = r%mod;
	}
	return r;
}
vector<int> pl(123456,0);
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);
	//cout<<161088479/4476118.0f<<endl;
	//cout<<161088479.0f/jie_chen(8)<<endl;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 0;i<n;i++) dif[i] = (char)s[i]-'0';
	for(int i = 0;i<n;i++) cin>>c[i];
	/*if(s.find('0')==string::npos){
		int yx = 0;
		for(int i = 0;i<n;i++) if(!(c[i]==0)) yx++;
		cout<<"yx="<<yx<<" else="<<n-yx<<endl;
		//cout<<jie_chen1(n-5,n)<<endl;
		if(n-yx>0) cout<<jie_chen(yx)*(ll)(yx+1)%mod<<endl;
		else cout<<jie_chen(n)<<endl;
	}*/
	for(int i = 0;i<n;i++) pl[i] = i;
	int cnt = 0;
	do{
		//for(int i = 0;i<n;i++)cout<<pl[i]<<' ';
		//cout<<endl;
		int fq = 0,cg = 0;
		for(int i = 0;i<n;i++){
			//printf("i=%d c=%d cg=%d fq=%d dif=%d\n",i,c[pl[i]],cg,fq,dif[i]);
			if(cg>=m){
				break;
			}
			if(fq>=c[pl[i]]){
				fq++;
				continue;
			}
			if(dif[i]==0) fq++;
			else cg++;
		}
		if(cg>=m) cnt++;
		cnt%=mod;
	}while(next_permutation(pl.begin(),pl.begin()+n));
	cout<<cnt<<endl;
	return 0;
}

