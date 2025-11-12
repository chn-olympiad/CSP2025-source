#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
long long ans,sum[500005]; 
string turn(int x){
	string s=to_string(x),s1="";
	int l=s.size();
	long long cnt=0;
	for(int i=1;i<=s.size();i++){
		s1+=s[i];
		int y=stoi(s1);
		cnt=cnt+y*pow(i);
		s1="";
	}
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	
	
	return 0;
}


