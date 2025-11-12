

#include <bits/stdc++.h>
using namespace std;
string s;
int n[1000000];
int main()
{	freopen("munber.in","r",in);
	freopen("munber.out","w",out);
	cin>>s;

		
	memset(n,sizeof(n),-1);
	long long k=0;
	for(int i=0;i<s.size();i++){
		if((s[i]>'0'*1) && (s[i]<='9'*1)) n[k++]=int(s[i]);
	}
	int a=0;
	for(long long i=k;i>=0;i--){
		for(long long j=0;j<=i;j++){
			if(n[j]<n[j+1]){
				a=n[j];
				n[j]=n[j+1];
				n[j+1]=a;
			}
		}
	}
	for(int i=0;n[i]>0;i++) cout<<n[i];
	return 0;
}

