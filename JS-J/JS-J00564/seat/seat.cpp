#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],t,num;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
     for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            num=i;
        }
    }
    if((num/n)%2==0&&num%n!=0){
        cout<<num/n+1<<" "<<num%n;
    }
    else if(num%n==0){
        if((num/n)%2==0)cout<<num/n<<" "<<1;
        else cout<<num/n<<" "<<n;
    }
    else cout<<num/n+1<<" "<<n-(num%n)+1;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
