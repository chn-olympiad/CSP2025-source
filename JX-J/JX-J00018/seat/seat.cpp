#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],l,mimi,zz;
    cin>>n>>m;
    cin>>a[1];
    mimi=a[1];
    int p=n*m;
    for(int i=2;i<=p;i++)cin>>a[i];
    sort(a+1,a+p+1);
    zz=p;
    l=1;
    while(1>0){
        if(l%2==1){
            for(int j=1;j<=m;j++){
                if(a[zz]==mimi){
                    cout<<l<<" "<<j;
                    return 0;
                }
                zz--;
            }
        }
        else {
            for(int j=m;j>=1;j--){
                if(a[zz]==mimi){
                    cout<<l<<" "<<j;
                    return 0;
                }
                zz--;
            }
        }
        l++;
    }
    return 0;
}
