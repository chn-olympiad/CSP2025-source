#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace2.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    string S[n][2],question[q][2];
    for(int i=0;i<n;i++){
        cin>>S[i][0]>>S[i][1];
    }
    for(int i=0;i<q;i++){
        cin>>question[i][0]>>question[i][1];
    }
    int sum[q]={0};
    for(int a=0;a<q;a++){
        for(long long i=0;i<question[a][0].size();i++){
            for(long long j=i;j<question[a][0].size();j++){
                string x="",y="",z="";
                if(i!=0)x+=question[a][0][i-1];
                for(long long s=i;s<=j;s++)y+=question[a][0][s];
                for(long long s=j+1;s<question[a][0].size();s++)z+=question[a][0][s];
                for(long long s=0;s<n;s++){
                    if(S[s][0]==y && x+S[s][1]+z==question[a][1])sum[a]++;
                }
            }
        }
    }
    cout<<1;
    for(int i=0;i<q;i++){
        cout<<sum[i]<<endl;
    }
}
