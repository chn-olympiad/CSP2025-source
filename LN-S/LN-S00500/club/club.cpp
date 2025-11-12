#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",std.in);
    freopen("club.out","w",std.out);
    int t,n,a[5],h=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            for(int k=1;k<=4;k++){
            	cin>>a[k];
            	
            }
            a.sort(0,a-1);
            h+=a[0];
        }
        
    	cout<<h<<endl;
    }
    return 0;
}
