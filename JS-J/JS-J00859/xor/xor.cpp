#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,a[500500],x[500500];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n+1;i++){
            cin>>a[i];
            x[i]=(x[i-1] xor a[i]);
           // cout<<x[i]<<" ";
	}
	//cout<<endl;
    for(int l=1,r=0;l<=n;l++){
        while(r<=n){
            r++;
            if((x[r] xor x[l-1])==k){
                //cout<<l<<" to "<<r<<endl;
                cnt++,l=r;
                break;
            }
            for(int i=l+1;i<=r;i++)
                if((x[r] xor x[i-1])==k){
                    //cout<<i<<" bto "<<r<<endl;
                    cnt++,l=r+1;
                    break;
            }
            //cout<<l<<"-"<<r<<" ";
        }
    }
    cout<<cnt;
	return 0;
}

