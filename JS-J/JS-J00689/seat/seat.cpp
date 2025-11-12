#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num=n*m,r_score;
    cin>>r_score;
    int sum=1;
    for(int i=2;i<=num;i++){
        int x;
        cin>>x;
        if(x>r_score) sum++;
    }
    cout<<((sum-1)/n)+1<<" ";
    if(((sum-1)/n)%2==0){
        cout<<(sum-1)%n+1;
    }else{
        cout<<n-((sum-1)%n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
