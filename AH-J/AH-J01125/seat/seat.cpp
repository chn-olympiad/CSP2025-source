#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &x,const int &y){
    return x>y;
}
int a[305],len;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[(i-1)*m+j];
            if(i==1&&j==1){
                len=a[(i-1)*m+j];
            }
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int cnt=0,x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt++;
            if(a[(i-1)*m+j]==len){
                len=cnt;
                break;
            }
        }
    }
    if(len%n==0){
        cout<<len/n<<' ';
        if(len/n%2==0) cout<<1<<' ';
        else cout<<n<<' ';
    }
    else{
        cout<<int(len/n)+1<<' ';
        if((int(len/n)+1)%2==0) cout<<n-(len-int(len/n)*n-1)<<' ';
        else cout<<len-int(len/n)*n<<' ';
    }
	return 0;
}
