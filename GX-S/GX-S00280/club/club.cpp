#include<bits/stdc++.h>
using namespace std;

int work(int n,vector<vector<int>> arr){
    int arr2[n][2];
    int res=0;
    vector<vector<int>> b(3,vector<int>());
    int maxnum=0;
    int index1=0;
    int midnum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]>maxnum){
                midnum=maxnum;
                maxnum=arr[i][j];
                index1=j;
            }
            if((arr[i][j]<maxnum) && (arr[i][j]>midnum)){
                midnum=arr[i][j];
            }
        }
        arr2[i][0]=maxnum;
        arr2[i][1]=midnum;
        if(b[index1].size()+1<=(n/2)){
            res+=maxnum;
            b[index1].push_back(i);
        }
        else{
            int sunshi=maxnum-midnum;
            for(int a=0;a<b[index1].size();a++){
                sunshi=min(sunshi,arr2[b[index1][a]][0]-arr2[b[index1][a]][1]);
            }
            res+=maxnum-sunshi;
        }
        maxnum=0;
        midnum=0;
        index1=0;
    }
    return res;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<vector<int>> arr(n,vector<int>(3,0));
        for(int j=0;j<n;j++){
                for(int k=0;k<3;k++){
                    cin>>arr[j][k];
                }
        }
        cout<<work(n,arr)<<endl;
    }
    return 0;
}
