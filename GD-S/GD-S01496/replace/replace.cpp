#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long n,q,b=977;
long long lent1,lent2,ht1,ht2;
char a[1000100];
struct node{
	long long len;
	long long h1,h2;
}s[1000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>10000||q>10000){
		while(q--) cout<<"0\n";
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a+1;
		s[i].len=strlen(a+1);
		cout<<s[i].len<<endl;
		for(long long j=1;j<=s[i].len;j++) s[i].h1=(s[i].h1*b+a[j]*a[j])%mod;
		cin>>a+1;
		for(long long j=1;j<=s[i].len;j++) s[i].h2=(s[i].h2*b+a[j]*a[j])%mod;
//		cout<<"The hash:"<<s[i].h1<<" "<<s[i].h2<<endl;//
	}
	for(long long i=1;i<=q;i++){
		lent1=lent2=0;
		ht1=ht2=0;
		long long ans=0,aww=1;
		cin>>a+1;
		lent1=strlen(a+1);
		for(long long j=1;j<=lent1;j++) ht1=(ht1*b+a[j]*a[j])%mod;
		cin>>a+1;
		lent2=strlen(a+1);
		if(lent2!=lent1){cout<<"0\n";continue;}
		for(long long j=1;j<=lent2;j++) ht2=(ht2*b+a[j]*a[j])%mod;
//		cout<<"The hash:"<<ht1<<" "<<ht2<<endl;//
		for(long long k=1;k<=n;k++){
			aww=1;
			for(long long sta=s[k].len;sta<=lent1;sta++){
				if((s[k].h1*aww%mod+ht2)%mod==(s[k].h2*aww%mod+ht1)%mod) ans++;
				aww=(aww*b)%mod;
			}
		}
		cout<<ans<<"\n";
	}
//	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex*/
