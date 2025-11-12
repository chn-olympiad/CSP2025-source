#include <cstdio>
#include <algorithm>
using namespace std;
int m,n,t;
int s[120];
struct node{
    int f,l;
};
node convert(int pc){
    node ans;
    ans.f = pc / m;
    ans.l = pc % m;
    if (ans.f % 2 != 0){
        ans.l = n - ans.l;
        ++(ans.f);
        return ans;
    }
    else{
        ++(ans.f);
        ++(ans.l);
        return ans;
    }
    return {-1,-1};
}
bool cmp(int a,int b){
    return a > b;
}
FILE *fin,*fout;
int main(){
    fin = fopen("seat.in","r");
    fout = fopen("seat.out","w");
    fscanf(fin,"%d %d\n",&n,&m);
    for (int i = 0;i != n*m-1;++i){
        fscanf(fin,"%d ",&s[i]);
    }
    t = s[0];
    sort(s,s+n*m-1,cmp);
    node pos;
    for (int i = 0;i != n*m-1;++i){
        if (s[i] == t){
            pos = convert(i);
        }
    }
    fprintf(fout,"%d %d",pos.f,pos.l);
    return 0;
}