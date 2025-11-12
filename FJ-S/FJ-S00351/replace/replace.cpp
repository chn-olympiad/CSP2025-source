#include<bits/stdc++.h>
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
const int M=6e6+6; 
const ull P=131;
int n,q;
ull pp[M];
ull h1[N];
ull h2[N];
ull s1[N];
struct node{
	ull x;ull y;
}has[N];
ull Hash(string s){
	int l=s.size();
	ull h=0;
	for(int i=0;i<l;i++){
		h=h*P+s[i];
	}
	return h;
}
ull get_hash1(ull l,ull r){
	return h1[r]-h1[l-1]*pp[r-l+1];
}
ull get_hash2(ull l,ull r){
	return h2[r]-h2[l-1]*pp[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	pp[0]=1;
	for(int i=1;i<=M-5;i++) pp[i]=pp[i-1]*P;
	for(int i=1;i<=n;i++){
		string a;string b;
		cin>>a>>b;
		s1[i]=a.size();
		has[i].x=Hash(a);
		has[i].y=Hash(b);
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ull l1=t1.size(),l2=t2.size();
		memset(h1,0,sizeof(h1));
		memset(h2,0,sizeof(h2));
		h1[0]=1;
		h2[0]=1;
		if(l1!=l2) {
			cout<<0<<endl;
			continue;
		}
		for(ull i=1;i<=l1;i++){
			h1[i]=h1[i-1]*P+t1[i-1];
		}
		for(ull i=1;i<=l2;i++){
			h2[i]=h2[i-1]*P+t2[i-1];
		}
		ull ans=0;
		//if(get_hash1(1,3)==get_hash1(4,6)) cout<<"yES"<<endl; 
		for(int i=1;i<=n;i++){
			ull x=has[i].x,y=has[i].y;
			ull xl=s1[i];
			for(ull j=1;j<=l1;j++){
				ull gh1=get_hash1(j,j+xl-1);
				ull gh2=get_hash2(j,j+xl-1);
				ull gh3=get_hash1(1,j-1);
				ull gh4=get_hash2(1,j-1);
				ull gh5=get_hash1(j+xl,l1);
				ull gh6=get_hash2(j+xl,l2);				
				//cout<<gh1<<gh2<<endl;
				if(x==gh1){
					if(y==gh2&&gh3==gh4&&gh5==gh6){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 




