#include<iostream>
#include<cstring>
using namespace std;

const int N=5010;

int a[N];
bool b[N];
int stick[N];
int mem[N];

int n;
int cnt=0;

void check(int p){
    int sum=0,max1=0;
    //cout<<p<<" ";
    for(int i=0;i<p;i++){
        int x=stick[a[i]];
        if(x>max1) max1=x;
        sum+=x;
        //cout<<x<<" ";
    }
    if(sum>max1*2) cnt++;
    //cout/*<<(sum>max1*2)*/<<endl;
}

void list1(int x){
    if(x>=3) check(x);
    int i;
    if(x==0) i=0;
    else i=a[x-1];
    for(;i<n;i++){
        if(b[i]==0){
            b[i]=1;
            a[x]=i;
            list1(x+1);
            b[i]=0;
        }
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&stick[i]);
    }
    a[0]=0;
    list1(0);

    printf("%d",cnt%998244353);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
