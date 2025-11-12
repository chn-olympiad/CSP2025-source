#include<bits/stdc++.h>
using namespace std;
int t,n,a[5],h=0;
int main(){
    freopen("replace.in","r",std.in);
    freopen("replace.out","w",std.out);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            for(int k=1;k<=4;k++){
            	cin>>a[k];
            	
            }
            sort(a,a-1);
            h+=a[0];
        }
        
    	cout<<h<<endl;
    }
    return 0;
}
