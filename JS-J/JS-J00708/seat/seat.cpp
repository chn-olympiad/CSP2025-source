#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],v[105],rr,ind,c=1,x,y;
bool cmp(int q,int q2){
    return q>q2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            rr=a[i];
        }
        v[i]=0;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==rr){
            ind=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(v[ind]==1){
            break;
        }
        if(i%2==1){
            for(int j=1;j<=n;j++){
                v[c]=1;
                if(c==ind){
                    x=i;
                    y=j;
                    break;
                }
                c++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                v[c]=1;
                if(c==ind){
                    x=i;
                    y=j;
                    break;
                }
                c++;
            }
        }
        if(v[ind]==1){
            break;
        }
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
