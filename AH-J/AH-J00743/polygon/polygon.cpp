#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005],cnt;
bool f1(long long x,long long y,long long z){
    int maxn=max(x,max(y,z));
    if(x+y+z>2*maxn){
        return 1;
    }
    return 0;
}
bool f2(long long x,long long y,long long z,long long q){
    int maxn=max(x,max(y,max(z,q)));
    if(x+y+z+q>2*maxn){
        return 1;
    }
    return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(f1(a[i],a[j],a[k])){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
