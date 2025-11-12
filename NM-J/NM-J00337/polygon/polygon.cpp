#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<a[i+1]){
    		swap(a[i],a[i+1]);
		}
		cout<<a[2];
        }
    return 0;
}

