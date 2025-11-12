#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s[100];
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    int t=s[0];
    sort(s,s+n*m,comp);
    int p;
    for(int i=0;i<n*m;i++){
        if(s[i]==t){
            p=i;
            break;
        }
    }
    p++;
    int q=ceil(p*1.0/n);
    cout<<q<<" "<<(q%2==1?(p%n?p%n:n):n-(p%n?p%n:n)+1)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}