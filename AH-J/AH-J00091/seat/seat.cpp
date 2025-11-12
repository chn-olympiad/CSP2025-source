#include<bits/stdc++.h>
#define line l
#define row r
#define target t
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int i,j;cin>>i>>j;
    int n=i*j;
    int a[n];
    for(int i=1;i<=n;i++) cin>>a[i];
    int score=a[1];
    sort(a+1,a+n+1);
    int target;
    for(int m=1;m<=n;m++){
        if(a[m]==score) {target=i*j+1-m;break;}
    }
//  cout<<score;
//  cout<<target;
    int line,row;
    for(int k=0;k<=j;k++){
        if(target>=k*j+1&&target<=(k+1)*j) line=k+1;
    }
//    cout<<line;
    int pre=target-(line-1)*i;//prev
    if(line%2==1) row=pre;
    else row=i+1-pre;
    cout<<line<<' '<<row;
    return 0;
}
