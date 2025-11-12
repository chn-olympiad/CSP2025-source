include<bits/stdc++.h>
using namespace std;
char x[100000];
int a[507]
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b=0,c=0;
    for(int i=1;i<=n;i++){
        if(x[i]=='1'||c<=a[i]){
            b++;
        }else{
            c++;
        }
    }
    cout<<b;


}


    return 0;
}
