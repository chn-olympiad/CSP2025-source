#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n*m+5,0);
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a.begin()+1,a.begin()+n*m+1,greater<int>());
    vector<vector<int> > s(n+5,vector<int>(m+5,0));
    int i=1,posi=1,posj=1;
    int ans=0;
    while(i<=n*m){
        if(a[i]==t){
            break;
        }
        s[posi][posj]=a[i];
        i++;
        if(posj&1){
            if(posi+1<=n){
                posi+=1;
            }
            else{
                posj+=1;
            }
        }
        else{
            if(posi-1>=1){
                posi-=1;
            }
            else{
                posj+=1;
            }
        }
    }
    cout<<posj<<" "<<posi;
    return 0;
}
