#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[110],R;
int x=1,y=1;
bool updown=1;
bool cmp(int a,int b){
    return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            cout<<x<<' '<<y;
            break;
        }
        else if(updown){
            if(y+1>n){
                x++;
                updown=0;
            }
            else{
                y++;
            }
        }
        else{
            if(y-1<1){
                x++;
                updown=1;
            }
            else{
                y--;
            }
        }
	}
    return 0;
}
