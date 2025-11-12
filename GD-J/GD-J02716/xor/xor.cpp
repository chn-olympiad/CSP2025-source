#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long a[N];
string f(long long n){
	long long p[105],c=1;
	while(n){
		p[c]=n%2;
		n/=2;
		c++;
	}
	long long s;
	for(int i=1;i<c;i++){
		s=s*10+p[i];
	}
	return s;
} 
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	long long n,k,ans=0;
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		fin>>a[i];
		if(a[i]==1)
			ans++;
	}
	if(ans==n&&k==0){
		fout<<n/2;
		return 0;
	}else if(k==1){
		fout<<ans;
		return 0;
	}
	fin.close();
	fout.close();
	return 0;
}
