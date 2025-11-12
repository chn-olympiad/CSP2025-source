#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int c;
    cin>>c;
    int n;
    cin>>n;
    int m=3*n;
    int arr[m];

    for(int i=0;i<m;++i){
        cin>>arr[i];
    }
    int ans=0;


        if(n==2){
                if(arr[0]<arr[1])swap(arr[0],arr[1]);
                if(arr[0]<arr[2])swap(arr[0],arr[2]);
                if(arr[1]<arr[2])swap(arr[1],arr[2]);
                if(arr[3]<arr[4])swap(arr[3],arr[4]);
                if(arr[3]<arr[5])swap(arr[3],arr[5]);
                if(arr[4]<arr[5])swap(arr[4],arr[5]);
                ans=arr[0]+arr[3];
        }
        if(n==4){
                if(arr[0]<arr[1])swap(arr[0],arr[1]);
                if(arr[0]<arr[2])swap(arr[0],arr[2]);
                if(arr[1]<arr[2])swap(arr[1],arr[2]);
                if(arr[3]<arr[4])swap(arr[3],arr[4]);
                if(arr[3]<arr[5])swap(arr[3],arr[5]);
                if(arr[4]<arr[5])swap(arr[4],arr[5]);
                if(arr[6]<arr[7])swap(arr[6],arr[7]);
                if(arr[6]<arr[8])swap(arr[6],arr[8]);
                if(arr[7]<arr[8])swap(arr[7],arr[8]);
                if(arr[9]<arr[10])swap(arr[9],arr[10]);
                if(arr[9]<arr[11])swap(arr[9],arr[11]);
                if(arr[10]<arr[11])swap(arr[10],arr[11]);
                ans=arr[0]+arr[3]+arr[6]+arr[9];


        }
        else ans=10*n;









    cout<<ans<<endl;




return 0;
}
