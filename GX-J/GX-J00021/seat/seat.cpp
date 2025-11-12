#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> arr;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int score;
        cin>>score;
        arr.push_back(score);
    }
    int A=arr[0],tmp;
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<int(arr.size());i++){
        if(arr[i]==A){
            tmp=i+1;
        }
    }
    int h=1,l=1,cnt=1;
    while(cnt!=tmp){
        if(l%2==1){
            h++;
            cnt++;
            if(h==n+1){
                l++;
                h--;
            }
        }
        else{
            h--;
            cnt++;
            if(h==0){
                l++;
                h++;
            }
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
