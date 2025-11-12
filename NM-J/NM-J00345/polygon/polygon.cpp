#include<bits/stdc++.h>
using namespace std;
int n,a[5100],ma=INT_MIN,s,c;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
		s=a[i];
        ma=a[i];
        for(int j=i+1;j<=k;j++){
        	s+=a[j];
            ma=max(ma,a[j]);
            if(s>ma*2&&j-i+1>=3){
                c++;
            }
    	}
    }
    cout<<c;
    return 0;
}
