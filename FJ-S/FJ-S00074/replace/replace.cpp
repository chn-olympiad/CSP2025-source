#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N=2e5+5;
const int L=5e6+15;
const int base=131;

int n,q;
ull ha1[N],hdf[N],pw[L],len[N];

ull Strhash(const string &s){
	ull ret=0;
	for(int i=0;i<s.size();i++){
		ret=ret+s[i]*pw[i];
	}
	return ret;
}


vector<ull> getsumvec(const string &s){
	vector<ull> ret(s.size());
	ret[0]=s[0];
	for(int i=1;i<s.size();i++){
		ret[i]=ret[i-1]+s[i]*pw[i];
	}
	return ret;
}

ull query(string s1,string s2){
	if(((double)clock())/CLOCKS_PER_SEC>0.9) return 0;
	int m=s1.size();
	ull ret=0;
	vector<ull> sum1=getsumvec(s1),sum2=getsumvec(s2);
	
//	cout<<"\n\nstart debug\n";
//	cout<<sum1[m-1]<<" "<<sum2[m-1]-sum1[m-1]<<"\n";
//	cout<<ha1[1]<<" "<<hdf[1]<<"\n";
//	cout<<"for debuging\n\n"<<endl;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j+len[i]-1<m;j++){
			
			ull h1=sum1[j+len[i]-1]-(j?sum1[j-1]:0);
			ull hd=sum2[m-1]-sum1[m-1];
			if(h1==ha1[i]*pw[j]&&hd==hdf[i]*pw[j]) ret++;
			
//			if(i==1){
//				cout<<"OOOHHH    "<<j<<" "<<j+len[i]-1<<" "<<m-1<<endl;
//				cout<<h1<<" "<<sum1[m-1]<<" "<<hd<<"\n\n"<<endl;
//			}
		}
	}
	return ret;
}

//void debug(){
//	return;
//	auto vv=getsumvec(string("what"));
//	cout<<vv[2]-vv[0]<<"\n";
//	cout<<Strhash("what")<<endl;
//	cout<<vv[3]<<endl;
//	cout<<Strhash(string("ha"))*131;
//	exit(0);
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	pw[0]=1;
	for(int i=1;i<=5e6+10;i++){
		pw[i]=pw[i-1]*base;
	}
	
//	debug();
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ha1[i]=Strhash(s1);
		hdf[i]=Strhash(s2)-ha1[i];
		len[i]=s1.size();
		
		
//		if(i==1){
//			cout<<"\n\nstop!\n";
//			ull hahaha=Strhash("xabcx");
//			cout<<hahaha<<"\n";
//			cout<<ha1[1]<<"\nover!\n\n";
//		}
	}
	
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<query(t1,t2)<<"\n";
	}
	return 0;
}
