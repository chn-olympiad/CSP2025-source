#include<bits/stdc++.h>
#define N 114514
using namespace std;
int a[N];
bool cmp(int c,int d){
	return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int x,y,s,x1=1,y1=1;
    cin>>x>>y;
    int n=x*y;
    for(int i=1;i<=n;i++)cin>>a[i];
    s=a[1];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
		if(a[i]!=s){
            x1++;
			if(x1>x){
				x1=x;
				y1+=1;
            }
            if(y1>y){
				y1=y;
				x1+=1;
			}
        }
        else {
				if(y1>y)y1=y;
				if(x1>x)x1=x;
                cout<<y1<<" "<<x1;
                return 0;
    }
   } 
	return 0;
}
