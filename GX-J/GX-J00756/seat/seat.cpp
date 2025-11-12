#include<bits/stdc++.h>
template<typename T>
inline T read(){T t=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9')f=c=='-',c=getchar();
    while(!(c<'0'||c>'9'))t*=10,t+=c-'0',c=getchar();
    return f?-t:t;
}
template<typename T>
inline void write(T t){
    if(t<0)putchar('-'),t=-t;
    if(t>9)write(t/10);
    putchar(t%10+'0');
}
using namespace std;
template<typename T>
class CCF{
    public:
    T score=0;
    T index=0;
    T rank=0;
    CCF(){}
    CCF(T a,T b):score(a),index(b){}
};
bool cmp1(CCF<int>a,CCF<int>b){
    return a.score>b.score;
}
bool cmp2(CCF<int>a,CCF<int>b){
    return a.index<b.index;
}
int n,m;
CCF<int>little_R;
int secret_const1,secret_const2;
vector<CCF<int>>a;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read<int>();m=read<int>();
    a.resize(n*m+1);
    for(int i=1;i<=n*m;i++){
        a[i].score=read<int>();
        a[i].index=i;
    }
    sort(a.begin()+1,a.end(),cmp1);
    for(int i=1;i<=n*m;i++)a[i].rank=i;
    sort(a.begin()+1,a.end(),cmp2);
    little_R=a[1];
    secret_const1=(little_R.rank-1)/n+1;
    secret_const2=(little_R.rank-1)%n+1;
    if(!(secret_const1%2))secret_const2=n-secret_const2+1;
    write(secret_const1);putchar(' ');write(secret_const2);
    putchar('\n');
    return 0;
}