#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road5.in","w",stdout);
    int n=10000,m=1000000,k=10;
    cout<<n<<" "<<m<<" "<<k<<"\n";
    for(int i=0;i<m;i++){
        int u=rand()%n+1,v=rand()%n+1,w=rand()%1000000000+1;
        if(i+1<n)u=i+1,v=i+2;
        cout<<u<<" "<<v<<" "<<w<<"\n";
    }
    for(int i=0;i<k;i++){
        cout<<rand()%1000000000+1<<" ";
        for(int i=0;i<n;i++)cout<<rand()%1000000000+1<<" \n"[i==n-1];
    }
    return 0;
}