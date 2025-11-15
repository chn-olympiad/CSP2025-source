#include<bits/stdc++.h>
using namespace std;
#define int long long
//g++ -O2 -std=c++14 -static a.cpp -o a
int arr[100005][4],mx=0;
void f(int A,int B,int C,int it,int sum,int num){
    if(it>=num){
        mx=max(mx,sum);
        return;
    }
    if(A<num/2)
        f(A+1,B,C,it+1,sum+arr[it][1],num);
    if(B<num/2)
        f(A,B+1,C,it+1,sum+arr[it][2],num);
    if(C<num/2)
        f(A,B,C+1,it+1,sum+arr[it][3],num);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    vector<int>v;
    while(t--){
        int n,i,sum=0;
        mx=0;
        cin>>n;
        bool b[n]={0};
        //vector<st>v;
        //int arr[n][4],dp[n][4];
        for(i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            arr[i][1]=a;
            arr[i][2]=b; 
            arr[i][3]=c;
        }
        f(0,0,0,0,0,n);
        v.push_back(mx);
        //cout<<mx<<endl;
    }
    for(int it:v)
        cout<<it<<endl;
}