#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m,a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1,t=1,f=0;
    do{
        if(a[t]==k){
            break;
        }

        if(f==0&&y>=1&&y<n){
            y++;
            t++;
            continue;
        }
        if(f==0&&y==n){
            x++;
            f=1;
            t++;
            continue;
        }
        if(f==1&&y<=n&&y>1){
            y--;
            t++;
            continue;
        }
        if(f==1&&y==1){
            x++;
            f=0;
            t++;
            continue;
        }


    }while(a[t-1]!=k);
    cout<<x<<" "<<y;

	return 0;
}
