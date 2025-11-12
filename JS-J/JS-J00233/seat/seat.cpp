#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int find(vector<int> v,int item){
    for(int i=0;i<v.size();i++){
        if(v[i]==item){
            return i;
        }
    }
    return -1;
}


int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n,m,score;
    cin>>n>>m;
    vector<int> v(n*m);
    for(int i=0;i<n*m;i++){
        cin >> v[i];
    }
    score = v[0];
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    int order,a,b;
    order = find(v, score);

    a=order/n+1;
    b=order%n+1;
    if(a%2==0){
        b=n+1-b;
    }
    cout<<a<<' '<<b;


    return 0;
}