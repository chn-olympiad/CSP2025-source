#include<bits/stdc++.h>
using namespace std;
long long n,m,k=0,x,y,q=1,ans=0,a[500050],b[500050];
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
    cin>>n>>m;
    if(m!=0){
        for(int i=1;i<=n;i++){
            cin>>x;
            if(x==m){
                ans++;
                k=0;
            }
            else k+=x;
            if(k%m==0&&k!=0){
                ans++;
                k=0;
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>x;
            if(x==0) ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}