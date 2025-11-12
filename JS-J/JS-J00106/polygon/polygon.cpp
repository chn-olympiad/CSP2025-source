#include<bits/stdc++.h>
using namespace std;
int n,a[5001],b[5001];
long long sum;
struct no{
    int a,b,c;
};
queue<no>q;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    /*(int i=0;i<n-2;i++){
        t=0;
        for(int j=i;j<n;j++){
            t+=a[j];
            if(j-i>=2){
                if(t<=a[j]*2){
                    continue;
                }
                sum++;
            }
        }
    }*/
    b[0]=a[0];
    for(int i=n-1;i>=0;i--){
        q.push({a[i],1,i});
        b[n-i]=b[n-i-1]+a[n-i];
    }
    while(!q.empty()){
        no f=q.front();
        for(int i=f.c-1;i>=0;i--){
            if(b[i]<f.a)break;
            if(f.a-a[i]<0){
                //sum+=f.c-3+f.b;
                for(int i=max(2-f.b,0);i<=f.c-1;i++){
                    for(int j=f.c-i-1;j>=i;j--){
                        sum+=(f.c-j)*(f.c-1-j)/2;
                        sum%=998244353;
                    }
                }
            }
            else q.push({f.a-a[i],f.b+1,i});
        }
        q.pop();
    }
    cout<<(sum%998244353);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
