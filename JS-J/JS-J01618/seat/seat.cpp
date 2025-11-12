#include<bits/stdc++.h>
using namespace std;
//#define freopen(file,mode,stream) (void)0
//#define fclose(stream) (void)0
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n*m);
    for(int i=0;i<n*m;i++){
        cin>>arr[i];
    }int r=arr[0];
    sort(arr.begin(),arr.end(),greater<int>());
    int c=0,l=0,up=1;
    for(int i:arr){
        if(i==r){
            cout<<(l+1)<<" "<<(c+1);
            break;
        }if(up==1&&c==n-1){
            l++;up=-1;
        }else if(up==-1&&c==0){
            l++;up=1;
        }else{
            c+=up;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
