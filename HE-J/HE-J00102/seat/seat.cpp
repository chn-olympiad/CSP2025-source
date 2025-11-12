#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
    int ans;
    int num;
};
vector<Node> a;
bool cmp(Node x,Node y){
    return x.ans>y.ans;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        Node s;
        int x;
        cin>>x;
        s.ans=x;
        s.num=i;
        a.push_back(s);
    }
    sort(a.begin(),a.end(),cmp);
    int k=0;
    for(int i=0;i<n*m;i++){
        if(a[i].num==1){
            k=i+1;
        }
    }
    int x,y;
    if(k%n!=0){
        x=x=k/n+1;
    }
    else{
        x=k/n;
    }
    if(x%2!=0){
        if(k%n==0){
            y=n;
        }
        else{
            y=k%n;
        }
    }
    else{
            y=n-((k-1)%n);
    }
    cout<<x<<" "<<y;
    return 0;
}
