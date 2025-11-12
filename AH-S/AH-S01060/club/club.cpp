#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long n=0,a[100005][4]={0},sum=0,x=0,y=0,z=0,T[200005],c=0,m=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                m=a[i][1];
                T[++c]=a[i][2]-m;
                T[++c]=a[i][3]-m;
                x++;
            }else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                m=a[i][2];
                T[++c]=a[i][1]-m;
                T[++c]=a[i][3]-m;
                y++;
            }else{
                m=a[i][3];
                T[++c]=a[i][2]-m;
                T[++c]=a[i][1]-m;
                z++;
            }
            sum+=m;
        }
        sort(T+1,T+c+1);
        /*for(int i=1;i<=c;i++){
            cout<<T[i]<<" ";
        }
        cout<<endl;*/
        if(x>n/2){
            for(int i=c;i>c-x+n/2;i--){
                sum+=T[i];
            }
        }else if(y>n/2){
            for(int i=c;i>c-y+n/2;i--){
                sum+=T[i];
            }
        }else if(z>n/2){
            for(int i=c;i>c-z+n/2;i--){
                sum+=T[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
