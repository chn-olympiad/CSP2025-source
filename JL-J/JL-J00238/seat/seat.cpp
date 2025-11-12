#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b,c=1,x,y;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    vector<int> vec;
    cin>>n>>m;
    cin>>b;
    vec.push_back(b);
    for(int i=0;i<n*m-1;i++){
        cin>>a;
        vec.push_back(a);
        c++;
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(vec[j]<vec[j+1]){
                int f=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=f;
            }
        }
    }
    for(int i=1;i<=c;i++){
        if(vec[i-1]==b){
            if(i*1.0/n==i/n){
                x=i/n;
            }
            else x=i/n+1;
            cout<<x<<" ";
            if(x%2==0){
                cout<<n+1-i%m<<endl;
            }
            else{
                if(i%m==0){
                    cout<<m-i%m<<endl;
                }
                else cout<<i%m;
            }
        }
    }
    fclose(stdin);
    return 0;
}
