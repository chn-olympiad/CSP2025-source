#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500000+10];
int j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int sum=a[i];
        j=1;
        while(sum!=k&&j<=n){
            sum=(sum^a[j]);
            j++;
        }
        for(int i=1;i<=n;i++){
            int sum=a[i];
            j=1;
            while(sum!=k&&j<=n){
                sum=(sum^a[j]);
                j++;
            }
        }
    }
	return 0;
}


