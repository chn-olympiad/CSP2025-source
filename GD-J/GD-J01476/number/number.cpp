#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int L=1e6+10;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

char st[L];
int l;

int cnt[520];

int main(){
    freopen("number.in","r",stdin);
//    freopen("number4.in","r",stdin);
    freopen("number.out","w",stdout);
	scanf("%s",st+1);
	l=strlen(st+1);
	
	for(int i=1;i<=l;i++){
		if(st[i]>='0' && st[i]<='9') cnt[st[i]-'0']++;
	}
	
	for(int i=9;~i;i--){
		if(cnt[i]){
			for(int j=1;j<=cnt[i];j++) putchar(i+'0');
		}
	}putchar('\n');
    return 0;
}
