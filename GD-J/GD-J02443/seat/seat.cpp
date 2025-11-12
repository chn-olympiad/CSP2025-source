#include<bits/stdc++.h>
using namespace std;
vector<int>seats;
bool cmp(const int &a,const int &b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    seats.resize(n*m-1);
    int mine;cin>>mine;
    for(auto&i:seats)cin>>i;
    sort(seats.begin(),seats.end(),cmp);
    auto it=lower_bound(seats.begin(),seats.end(),mine,cmp);
    if(it==seats.begin())cout<<"0 0";
    else {
        
        int pos=it-seats.begin()+1,remain,lie=(pos-1)/n+1,hang;
        if(pos%n==0)remain=n;
        else remain=pos%n;
        if(lie%2)hang=remain;
        else hang=n-remain+1;
        cout<<lie<<' '<<hang;
    }
    fclose(stdin);fclose(stdout);
}