#include<bits/stdc++.h>
using namespace std;
vector<long long> c;
string s;
vector<bool> yes;
vector<long long> tiaoshi;
long long m;
int js(long long deep,long long kill){
//	printf("启动deep=%lld kill=%lld 难度c=%d\n调试信息:",deep,kill,s[deep-1]);
//	for(long long a=1;a<tiaoshi.size();a++){
//		cout<<tiaoshi[a]<<" ";
//	}
//	cout<<"\n";
	long long h=0;
	if(deep==yes.size()){
		if(s.size()-kill>=m){
//			for(long long a=1;a<tiaoshi.size();a++){
//				cout<<tiaoshi[a]<<" ";
//			}
//			cout<<"\n"<<kill<<"\n";
			return 1;
		}
		return 0;
	}
	for(long long a=1;a<yes.size();a++){
		if(!yes[a]){
			yes[a]=1;
			tiaoshi[deep]=a;
			h+=js(deep+1,(s[deep-1]=='1'?(kill<c[a]?kill:kill+1):1+kill));
			yes[a]=0;
		}
	}
	return h;
}
int main(){
	ifstream fin("employ.in");
	ofstream fout("employ.out");
	long long a,b,d,e,f,g,h,i,j,k,l,n,o,p,q,r,t,u,v,w,x,y,z;
	fin>>n>>m;
	fin>>s;
	tiaoshi.resize(n+1);
	c.resize(n+1);
	yes.resize(n+1);
	for(a=1;a<=n;a++){
		fin>>c[a];
	}
	fout<<js(1,0);
	return 0;
}
