#include<bits/stdc++.h>
using namespace std;
int n,k,a[257];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
	int res=0;
    for(int l=0;l<n;l++){
		int bin=0;
        for(int r=l;r<n;r++){
            for(int i=l;i<=r;i++){
            	cout<<bin<<" ";
                bin=bin-a[i];
                cout<<bin<<endl;
            }
            cout<<endl;
            if(bin==k||bin==-k){
                res++;
                break;
            }
        }
    }
    cout<<res;
    return 0;
}
