#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int cmp(int x,int y){return x>y;}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int s=n*m;
for(int i=1;i<=s;i++){
	cin>>a[i];
}
int b=a[1],x=1,y=1;
sort(a+1,a+s+1,cmp);
for(int i=1;i<=s;i++){
	if(a[i]==b){
        cout<<x<<" "<<y;
        return 0;
	}
	if(x%2==1){
        if(y==n){
            x++;
        }
        else y++;
	}
	else{
        if(y==1){
            x++;
        }
        else y--;
	}
}
 return 0;
}
