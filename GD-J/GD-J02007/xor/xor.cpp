#include<bits/stdc++.h>
using namespace std;
long long n,k,a,s[500001],t[10000001],f,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(t,-1,sizeof(t));
	t[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
		int b=s[i]^k;
		if(!b&&!f){
			f=i;
			c++;
			t[s[i]]=i;
			continue;
		}
		if(t[b]>=f){
			c++;
			f=i;
		}
		t[s[i]]=i;
	}
	cout<<c;
}
