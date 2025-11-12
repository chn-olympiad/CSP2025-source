#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1,sc;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int s;
        cin>>s;
        if(i==1) sc=s;
        if(s>sc) cnt++;
    }
    int lie,hang;
    if(cnt%n==0) lie=cnt/n;
    else lie=cnt/n+1;
    if(lie%2==1){
        if(cnt%n==0) hang=n;
        else hang=cnt%n;
    }else{
        hang=lie*n-cnt+1;
    }
    cout<<lie<<" "<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
