#include<bits/stdc++.h>
using namespace std;
vector<int> wood(10,0);
int num[5500]={0};
int sum=0,maxs=0;
int BFS(int num,vector<int> wood){

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int a=0;
    if(n<3){
        cout<<0;
    }
    if(n==3){
        if(num[0]+num[1]>num[2]){
            a++;
        }
        if(num[0]+num[2]>num[1]){
            a++;
        }
        if(num[1]+num[2]>num[0]){
            a++;
        }
    }
    cout<<a;
    fclose(stdin);
    fclose(stdout);
}
