#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int arr[100050][5];
int ma;
long long int ans[100050];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int q=0;q<t;q++)
    {
        cin>>n;
        ma=0;
        for(int w=0;w<n;w++)
        {
            cin>>arr[w][0]>>arr[w][1]>>arr[w][2];
            if(arr[w][0]==arr[w][1]==arr[w][2])
            {
                ma+=arr[w][0];
            }
            else if(arr[w][0]==arr[w][1] && arr[w][2]>arr[w][0])
            {
                ma+=arr[w][2];
            }
            else if(arr[w][0]==arr[w][2] && arr[w][1]>arr[w][0])
            {
                ma+=arr[w][1];
            }
            else if(arr[w][1]==arr[w][2] && arr[w][0]>arr[w][2])
            {
                ma+=arr[w][0];
            }
            else if(arr[w][0]>arr[w][1] && arr[w][0]>arr[w][2])
            {
                ma+=arr[w][0];
            }
            else if(arr[w][1]>arr[w][0] && arr[w][1]>arr[w][2])
            {
                ma+=arr[w][1];
            }
            else
            {
                ma+=arr[w][2];
            }
        }
        ans[q]=ma;
    }
    for(int i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
