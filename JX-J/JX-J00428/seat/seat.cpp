#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,num,idx;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    num=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==num){
            idx=i;
            break;
        }
    }
    int line=1,row=1;
    for(int i=2;i<=idx;i++){
        if(line&1){
            row++;
            if(row>n){
                line++;
                row=n;
            }
        }else{
            row--;
            if(row<1){
                line++;
                row=1;
            }
        }
    }
    cout<<line<<" "<<row;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
