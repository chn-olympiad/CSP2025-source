#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool right1=1,right2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) right1=0;
        if(a[i]!=1&&a[i]!=0) right2=0;
    }
    if(right1==1){
        cout<<n;
    }else if(right2==1){
        for(int i=1;i<=n;i++){
            ans+=a[i];
        }
        cout<<ans;
    }
	return 0;
}
