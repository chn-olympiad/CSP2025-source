#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,n,m;
    cin>>n>>m;
    vector<int> S(n*m);
    for(int i = 0;i<n*m;i++){
        cin>>S[i];
    }
    a = S[0];
    sort(S.begin(),S.end());
    reverse(S.begin(),S.end());
    int pos = distance(S.begin(),find(S.begin(),S.end(),a))+1;
    int am,an;
    am = pos % n > 0? pos /n +1 : pos/ n;
    an = pos%(2*n)<=n? pos %(2*n) : 2*n - pos%(2*n) + 1;
    if(pos%(2*n)==0){
        an = 1;
    }
    cout<<am<<" "<<an<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
