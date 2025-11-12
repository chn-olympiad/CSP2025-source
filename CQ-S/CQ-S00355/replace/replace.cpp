#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
#define il inline
#define re register
using namespace std;
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(48^ch);
		ch=getchar();
	}
	return x*f;
}
const int N=2e5+5;
string s[N][5],t[N][5];
struct sss{
	int xb,num;
}mpz[N],mpf[N];
int sizs[N],sizt[N];
int fib[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	int fb,lb;
	for(int i=n;i>=1;i--){
		cin>>s[i][0]>>s[i][1];
		sizs[i]=s[i][0].size();
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='b'){
				fb=j;
			}
			if(s[i][1][j]=='b'){
				lb=j;
			}
		}
		fib[i]=fb;
		int pz=mpz[fb-lb].num,pf=mpf[abs(fb-lb)].num;
		if(fb-lb>0) mpz[fb-lb]={i,++pz};
		else mpf[abs(fb-lb)]={i,++pf};
	} 
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		sizt[i]=t[i][0].size();
		if(t[i][0].size()!=t[i][1].size()){
			cout<<0<<endl;
			continue;
		}
		int db,eb;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]=='b') db=j;
			if(t[i][1][j]=='b') eb=j;
		}
		if(db-eb>0&&sizs[mpz[db-eb].xb]<=sizt[i]&&fib[mpz[db-eb].xb]<=db){
			cout<<mpz[db-eb].num<<endl;
		}
		else if(db-eb<0&&sizs[mpf[abs(db-eb)].xb]<=sizt[i]&&fib[mpf[abs(db-eb)].xb]<=db){
			cout<<mpf[abs(db-eb)].num<<endl;
		}
		else cout<<0<<endl;
	}
	
	return 0;
}
/*
8 4
ab ba
ba ab
baa aba
baa aab
aba baa
aba aab
aab baa
aab aba
aabaa aaaab
baaaa aabaa
aabaa aaaba
abaaa aabaa



8 4
ab ba 1
ba ab -1
baa aba 1
baa aab 2
aba baa -1
aba aab 1
aab baa -2
aab aba -1
aabaa aaaab 2
baaaa aabaa 2
aabaa aaaba 1
abaaa aabaa 1
*/
