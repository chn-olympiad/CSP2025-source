#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[102];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int id;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int temp_=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(temp_==a[i]){
            id=i;
        }
    }
    int n_ans,m_ans;
    if(id%n==0){
        m_ans=id/n;
        if(m_ans%2==0){
            n_ans=1;
        }
        else{
            n_ans=n;
        }
    }
    else{
        m_ans=id/n+1;
        if(m_ans%2==1){
            n_ans=id%n;
        }
        else{
            n_ans=n-(id%n)+1;
        }
    }
    cout<<m_ans<<' '<<n_ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
