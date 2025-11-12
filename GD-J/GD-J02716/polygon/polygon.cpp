#include<bits/stdc++.h>
using namespace std;
const int N=5015;
long long a[N],s[N];
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	long long n;
	fin>>n;
	bool vis=1;
	for(int i=1;i<=n;i++){
		fin>>a[i];
		s[i]=s[i-1]+a[i];
		if(a[i]!=1)
			vis=0;
	}	
	if(vis){
		fout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long ans=-1;
			for(int k=1;k<=j;k++)
				ans=max(ans,a[k]);
			if(s[i]>ans*2)
				cnt++;
		}
	}
	fout<<cnt;
	fin.close();
	fout.close();
	return 0;
}
