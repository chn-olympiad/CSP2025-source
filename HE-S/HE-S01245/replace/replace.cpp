#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
int mod=2147483647;
int base=131;
string c,d;
struct node{
	int len;
	int ha,hb;	
}s[200010];
int h1[5000010],h2[5000010];
int pwr[5000010];
int hsh(string str){
	int l=str.size(),tot=0;
	for(int i=0;i<l;i++){
		tot=((tot*base)%mod+str[i])%mod;
	}
	return tot;
}
int que1(int l,int r){
	return (h1[r]-h1[l-1]*pwr[r-l+1]+mod)%mod;
}
int que2(int l,int r){
	return (h2[r]-h2[l-1]*pwr[r-l+1]+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	pwr[0]=1;
	for(int i=1;i<5000010;i++){
		pwr[i]=(pwr[i-1]*base)%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>c;
		cin>>d;
		s[i].len=c.size();
		s[i].ha=hsh(c);
		s[i].hb=hsh(d);
	}
	for(int k=1;k<=q;k++){
		ans=0;
		cin>>c;
		cin>>d;
		if(c.size()!=d.size()){
			printf("0\n");
			continue;
		}
		int ls=c.size();
		for(int i=0;i<ls;i++){
			h1[i]=((h1[i-1]*base)%mod+c[i])%mod;
			h2[i]=((h2[i-1]*base)%mod+d[i])%mod;
		}	
		for(int i=1;i<=n;i++){
			int tot=0;
			if(s[i].len>ls){
				continue;
			}
			for(int l=0;l+s[i].len-1<ls;l++){
				int r=l+s[i].len-1,flag=1;
				if(l&&c[l-1]!=d[l-1]){
					break;
				}
				if(que1(l,r)==s[i].ha&&que2(l,r)==s[i].hb){
					for(int j=r+1;j<ls;j++){
						if(c[j]!=d[j]){
							flag=0;
							break;
						}
					}
					tot+=flag;
				}
			}
			ans+=tot;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
