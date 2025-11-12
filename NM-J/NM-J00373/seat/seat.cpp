#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);

    int n,m;
	cin>>n>>m;
    vector<int> arr(n*m+1);
    for (int i=1;i<=n*m;i++){
    	cin>>arr[i];
    }
    int a=arr[1];
    int sl=0;
    sort(arr.begin(),arr.end());
    for (int i=1;i<arr.size();i++){
        if (arr[arr.size()-i]==a){
            sl=i;
            break;
        }
    }
    int c,r;
    c=ceil(double(sl)/n);
    if (sl%n==0){
        r=n;
        cout<<c<<' '<<r;
        return 0;
    }
    r=c%2==1?sl%n:n-sl%n+1;
    cout<<c<<' '<<r;
    
    return 0;
}
