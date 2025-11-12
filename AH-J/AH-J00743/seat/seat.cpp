#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=1,y=1,p,s;
bool f=0;
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
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            s=i;
            break;
        }
    }
    if(s==1){
        cout<<1<<" "<<1;
        return 0;
    }
    int cnt=1;
    while(1){
        if(!f) y++;
        else y--;
        if(y>m|y<1){
            f=!f;
            x++;
            if(y>m) y--;
            else y++;
        }
        cnt++;
        if(cnt==s){
            cout<<x<<" "<<y;
            return 0;
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
