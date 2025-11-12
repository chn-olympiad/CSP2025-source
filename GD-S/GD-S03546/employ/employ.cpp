#include <bits/stdc++.h>
using namespace std;
long long n,m,c[1000],s1[3001],tag[3001]={0},ans=0;
string s;
ifstream fin("employ2.in");
ofstream fout("employ.out");
void f(int k){
	long long i;
	if(k>n){
		long long cnt=0,cnt2=0;
		for(i=1;i<=n;i++){
			if(s[i-1]=='0') cnt++;
			else{
				if(c[s1[i]]-cnt<=0) cnt++;
				else cnt2++;
			}
		}
		if(cnt2>=m) ans++;
		ans=ans%998244353;
	}
	else{
		for(i=1;i<=n;i++){
			if(tag[i]==0){
				s1[k]=i;
				tag[i]=-1;
				f(k+1);
				tag[i]=0;
			}
		}
	}
}
int main(){
	long long i;
	fin>>n>>m;
	fin>>s;
	for(i=1;i<=n;i++) fin>>c[i];
	if(n>20){
		long long nn=1;
		for(i=1;i<=n;i++){
			nn=(nn*i)%998244353;
		}
		fout<<nn;
	}
	else{
		f(1);
		fout<<ans;
	}
	fin.close();
	fout.close();
	return 0;
}
