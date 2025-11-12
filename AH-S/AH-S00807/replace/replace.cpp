#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL,LL>
using namespace std;
const LL N=2e6+10;
const LL M1=1e9+7,M2=1e9+9,p=67;
LL n,q;
map<pair<PLL,PLL>,LL> mp;
void write(LL x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
LL turn(char ch){return ch-'a'+1;}
void cun_hash(string s1,string s2){
	LL h1,h2,h3,h4;
	h1=h2=h3=h4=0;
	LL len=s1.size();
	for(LL i=1;i<=len;i++)
		if(s1[i-1]!=s2[i-1]) 
		{
			h1=((h1*p+turn(s1[i-1]))%M1+M1)%M1;
			h2=((h2*p+turn(s1[i-1]))%M2+M2)%M2;
			h3=((h3*p+turn(s2[i-1]))%M1+M1)%M1;
			h4=((h4*p+turn(s2[i-1]))%M2+M2)%M2;
		}
//		else{
//			h1*=p;
//			h2*=p;
//			h3*=p;
//			h4*=p;
//		}
//	cout<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<endl;
	mp[make_pair(make_pair(h1,h2),make_pair(h3,h4))]++;
}
void suan_hash(string s1,string s2){
	LL h1,h2,h3,h4;
	h1=h2=h3=h4=0;
	LL len=s1.size();
	for(LL i=1;i<=len;i++)
		if(s1[i-1]!=s2[i-1])
		{
			h1=((h1*p+turn(s1[i-1]))%M1+M1)%M1;
			h2=((h2*p+turn(s1[i-1]))%M2+M2)%M2;
			h3=((h3*p+turn(s2[i-1]))%M1+M1)%M1;
			h4=((h4*p+turn(s2[i-1]))%M2+M2)%M2;
		}
//		else{
//			h1*=p;
//			h2*=p;
//			h3*=p;
//			h4*=p;
//		}
//	cout<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<endl;
	write(mp[make_pair(make_pair(h1,h2),make_pair(h3,h4))]);puts("");
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(LL i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		cun_hash(s1,s2);
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) puts("0");
		else suan_hash(s1,s2);
	}
	return 0;
}
