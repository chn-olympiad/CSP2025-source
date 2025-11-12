#include<bits/stdc++.h>
using namespace std;
int a[1000],ans[1000];
int main(){
    freopen("seat2.in","r",stdin);
    freopen("seat2.out","w",stdout);
    int n,m,b,me,my;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=n*m;
    me=a[1];
    sort(a,a+b+1);
    int j=1;
    for(int i=b;i>=1;i--){

       ans[j]=a[i];
       j++;

    }
for(int i=1;i<=b;i++){
    if(ans[i]==me){

        my=i;
        break;
       }
}
int jj;
jj=my/m;
if(jj%2==1){
    cout<<jj+1<<" "<<abs(my-((jj)*n)-n)+1;
}
else{
        jj=my/m;
    cout<<jj+1<<" "<<my%n;
    }
    return 0;
}
