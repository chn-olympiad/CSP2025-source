#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD1=3331;
const int MOD2=13331;
const int MOD3=100007;
const int N=2*1e5+5;
string s1[N],s2[N];
int hash1[N],hash2[N],hash3[N];
int ksm(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1)res=(res*a)%p;
        a=(a*a)%p,b>>=1;
    }
    return res;
}
int get_hash1(string s){
    int len=s.length()-1,Hash=0;
    for(int i=1;i<=len;i++)Hash=(Hash*20%MOD1+s[i]-'a')%MOD1;
    return Hash;
}
int get_hash2(string s){
    int len=s.length()-1,Hash=0;
    for(int i=1;i<=len;i++)Hash=(Hash*57%MOD2+s[i]-'a')%MOD2;
    return Hash;
}
int get_hash3(string s){
    int len=s.length()-1,Hash=0;
    for(int i=1;i<=len;i++)Hash=(Hash*77%MOD3+s[i]-'a')%MOD3;
    return Hash;
}
int cal1(int a,int b){return (a%MOD1-b%MOD1+MOD1)%MOD1;}
int cal2(int a,int b){return (a%MOD2-b%MOD2+MOD2)%MOD2;}
int cal3(int a,int b){return (a%MOD3-b%MOD3+MOD3)%MOD3;}
signed main(){
	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)cin.ignore(),cin>>s1[i]>>s2[i],s1[i]='0'+s1[i],s2[i]='0'+s2[i];
	while(q--){
        string x,y;
        cin>>x>>y;
        if(x.length()!=y.length()){printf("0\n");continue;}
        int m=x.length();
        x='0'+x,y='0'+y;
        for(int i=1;i<=m;i++){
            hash1[i]=(hash1[i-1]*20%MOD1+x[i]-'a')%MOD1;
            hash2[i]=(hash2[i-1]*57%MOD2+x[i]-'a')%MOD2;
            hash3[i]=(hash3[i-1]*77%MOD3+x[i]-'a')%MOD3;
        }
        int ans=0;
        int an1=get_hash1(y);
        int an2=get_hash2(y);
        int an3=get_hash3(y);
        for(int i=1;i<=n;i++){
            int len=s1[i].length()-1;
            int ex1=get_hash1(s1[i]);
            int ex2=get_hash2(s1[i]);
            int ex3=get_hash3(s1[i]);
            int Ex1=get_hash1(s2[i]);
            int Ex2=get_hash2(s2[i]);
            int Ex3=get_hash3(s2[i]);
            for(int j=1;j+len-1<=m;j++){
                if((hash1[j+len-1]-hash1[j-1]*ksm(20,len,MOD1)%MOD1+MOD1)%MOD1==ex1&&
                   (hash2[j+len-1]-hash2[j-1]*ksm(57,len,MOD2)%MOD2+MOD2)%MOD2==ex2&&
                   (hash3[j+len-1]-hash3[j-1]*ksm(77,len,MOD3)%MOD3+MOD3)%MOD3==ex3){
                    int f=1;
                    for(int k=1;k<=m;k++){
                        if(j<=k&&k<=j+len-1)if(y[k]!=s2[i][k-j+1]){f=0;break;}
                        else if(x[k]!=y[k]){f=0;break;}
                    }
                    if(f==1)ans++;
                }
            }
        }
        printf("%lld\n",ans);
	}
	return 0;
}
