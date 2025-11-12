#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=0,x=1,y=1,f=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            r=a[i];
        }
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            cout<<y<<" "<<x;
            break;
        }
        if(x==n&&f==1){
                y++;
                x=n;
                f=-1;
        }
        else if(x==1&&f==-1){
			x=1;
            y++;
            f=1;
        }
        else{
            x+=f;
        }
	}
	return 0;
}
