#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int score[105];
int xiaor;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>score[i];
    }
    xiaor=score[1];
    sort(score+1,score+sum+1,cmp);
    for(int i=1;i<=sum;i++){
        if(score[i]==xiaor){
            int lie=i;
            lie+=n-1;
            lie/=n;
            i-=(lie-1)*n;
            if(lie%2==1){
                cout<<lie<<" "<<i;
            }else{
                cout<<lie<<" "<<n-i+1;
            }
            return 0;
        }
    }
    return 0;
}
