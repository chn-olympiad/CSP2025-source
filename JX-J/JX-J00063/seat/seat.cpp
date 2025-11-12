#include<bits/stdc++.h>
#define ll long long
#define N 10000010
#define M 1010
using namespace std;
ll n,m,a[N],x,y,t,d,s;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            d=i;
            break;
        }
	}
	x=0,y=1;
	for(int i=1;i<=n*m;i++){

        if(s==0&&x<n){
            ++x;
        }
        else if(s==0&&x==n){
            s=1;
            y++;
        }
        else if(s==1&&x>1){
            --x;
        }
        else{
            s=0;
            y++;
        }
     //   cout<<x<<" "<<y<<" "<<a[i]<<endl;
        if(i==d){
            cout<<y<<" "<<x<<endl;
            break;
        }
	}
    return 0;
}
