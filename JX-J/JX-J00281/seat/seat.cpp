#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);
    int ansx=1,ansy=1,line=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==num) break;
        if(line%2==0)ansy--;
        else ansy++;
        if((ansy>n&&line%2==1)||(ansy<1&&line%2==0)){
            if(line%2==1)ansy=n;
            else ansy=1;
            line++;
            ansx++;
			if(ansx>m)ansx%=m;
        }
    }
    cout<<ansx<<" "<<ansy;
    return 0;
}

