#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    vector<vector<int> > s;
    int n,m;
    int an,am;
    int r;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int f;
        cin>>f;
        s.push_back({f,0});
    }
    s[0][1]=1;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i][0]>s[j][0]){
                vector<int> c=s[i];
                s[i]=s[j];
                s[j]=c;
            }
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i][1]==1){
            r=i+1;
            break;
        }
    }
    cout<<r<<endl;
    if(r%n==0){
        am=r/n;
    }else{
        am=r/n+1;
    }
    if(r%(2*n)>n){
        an=2*n-r%(2*n)-1;
    }else{
        an=r%n+1;
    }
    cout<<an<<" "<<am<<endl;
    return 0;
}
