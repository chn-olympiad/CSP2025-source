#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[1000010];
ll temp=0;

int main(){
	
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    cin>>n;
    for(ll i=0;n>0;i++){
        a[i]=n%10;
        n/=10;
        temp++;
    }
    sort(a+0,a+temp+0);
    for(ll i=temp-1;i>=0;i--){
    	cout<<a[i];
	}
    return 0;
}
