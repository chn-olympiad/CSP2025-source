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

const int N=5e2+10;
const LL P=998244353;

int n,m;
int c[N];

char st[N];

int ans;
namespace sub1{
    int a[N];
    int getfac(int x){
        int s=1;
        for(int i=1;i<=x;i++) s*=i;
        return s;
    }
    void bl(){
        for(int i=1;i<=n;i++) a[i]=i;
        
        // int tn=getfac(n);
        do{
            int cnt=0;
            int succnt=0;// success_cnt
            for(int i=1;i<=n;i++){
                if(cnt>=c[a[i]]){
                    cnt++;
                    continue;
                }
                if(st[i]=='0'){
                    cnt++;
                }
                else{
                    succnt++;
                }
            }
            // if(cnt>=m) ans++;
            if(succnt>=m) ans++;
        }while(next_permutation(a+1,a+n+1));

        printf("%d\n",ans);
        return;
    }
};

int main(){
	freopen("employ.in","r",stdin);
	// freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	
    scanf("%d %d",&n,&m);
    scanf("%s",st+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);

    if(n<=10){
        sub1::bl();
        return 0;
    }
	return 0;
}
// 18!=6,402,373,705,728,000