#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void test(){
	int n,A=0,B=0,C=0;
	int num=0,ans=0,sum=0,max=0;
	cin>>n;
	for(int j=1;j<=n;j++){
		int a,b,c;
		cin>>a>>b>>c; 
		if(a>b&&a>c){
			A++;
			num+=a;
			if(A==n/2) continue;
		}
		if(b>a&&b>c){
			B++;
			ans+=b;
			if(B==n/2) continue;
		}
		if(c>a&&c>b){
			C++;
			sum+=c;
			if(C==n/2) continue;
		}
		max=num+ans+sum;
	}
	cout<<max<<endl;
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int t;
	cin>>t;
	while(t--) test();
	return 0;
}

