#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> num;
    int record;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            if(i==0 && j==0)
                record=x;
            num.push_back(x);
        }
    }
    int s;
    sort(num.begin(),num.end());
    int j=0;
    for(int i=num.size()-1;i>=0;i--){
            j++;
        if(num[i]==record){
            s=j;
        }
    }
    int x,y;
    if(s%n==0){
        x=s/n;
        if(x%2==0){
            if(s%n==0){
                y=1;
            }
            else{
                y=s%n;
                y=m-y+1;
            }
        }
        else{
            if(s%n==0){
                y=n;
            }
            else{
                y=s%n;
            }
        }
    }
    else{
        x=s/n + 1;
        if(x%2==0){
            if(s%n==0){
                y=1;
            }
            else{
                y=s%n;
                y=m-y+1;
            }
        }
        else{
            if(s%n==0){
                y=n;
            }
            else{
                y=s%n;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
