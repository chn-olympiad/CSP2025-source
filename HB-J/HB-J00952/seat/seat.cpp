#include<bits/stdc++.h>
using namespace std;
struct aaa{
    int grade;
    int id;
} e[1010];
bool cmp(aaa x,aaa y){
    return x.grade>y.grade;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>e[i].grade;
        e[i].id=i;
    }
    sort(e+1,e+k+1,cmp);
    int flag=0;
    for(int i=1;i<=k;i++){
        if(e[i].id==1){
            flag=i;
        }
    }
    int x=flag/n+1;
    int y;
    if(x%2==1){
        y=flag%n;
    }
    else{
        y=n-(flag%n)+1;
    }
    cout<<x<<" "<<y;
	return 0;
}
