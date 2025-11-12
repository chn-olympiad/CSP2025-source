#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=3e6+10,mod=1e9+7;
mt19937 gen(time(NULL));
unordered_map<ull,int> mp;
ull s1,s2,s3;
string a,b;
int n,q;
ull geth(ull x,ull y){
	ull ret=0;
	x^=(x<<31)^s1;x^=(x<<33)^s2;x^=(x<<13)^s3;
	y^=(y<<31)^s1;y^=(y<<33)^s2;y^=(y<<13)^s3;
	while(x) {ret=ret*s3+x%10;x/=10;}
	while(y) {ret=ret*s2+y%10;y/=10;}
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	s1=gen();s2=gen();s3=gen();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b; int len=a.size();
		ull x=0,y=0;
		for(int i=l;i<=r;i++){
			x=x*131+a[i]-'a'+1;
			y=y*131+b[i]-'a'+1;
		}
		ull tem=geth(x,y);
//		cout<<x<<" "<<y<<" "<<tem<<"\n";
		mp[tem]++;
	}
//	cout<<"\n";
	for(int i=1;i<=q;i++){
		cin>>a>>b; int len=a.size();
		ull x=0,y=0;
		for(int i=0;i<len;i++){
			x=x*131+a[i]-'a'+1;
			y=y*131+b[i]-'a'+1;
		}
		ull tem=geth(x,y);
//		cout<<x<<" "<<y<<" "<<tem<<"\n";
		cout<<mp[tem]<<"\n";
	}
	return 0;
}

