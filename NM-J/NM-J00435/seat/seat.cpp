#include <bits/stdc++.h>
using namespace std;
int flag,found;
int lie,hang;
int b[105];
struct node{
    int s,num;
};
node a[105];
bool cmp(node a,node b){
    if(a.s!=b.s) return a.s>b.s;
    return a.num<b.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i].s;
        if(i==1){
            flag=a[i].s;
        }
        a[i].num=i;
    }

    sort(a+1,a+1+sum,cmp);


    for(int i=1;i<=sum;i++){
        int v=a[i].s;
        if(v==flag&&a[i].num==1){
            found=i;
        }
    }

    if(found%n==0){
        lie=found/n;

    }else{
        lie=found/n+1;
    }

    if(lie%2==0){
            hang=n+1-(found-(lie-1)*n);
        }
    else{
            hang=found-(lie-1)*n;
        }


    cout<<lie<<" "<<hang;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
