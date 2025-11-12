#include<bits/stdc++.h>
using namespace std;
int n,m,rs,cspj[105];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)cin >> cspj[i];
    rs=cspj[1];
    sort(cspj+1,cspj+n*m+1,cmp);
    if(rs==cspj[1]){
        cout << "1 1";
        return 0;
    }
    //for(int i=1;i<=n*m;i++)cout << cspj[i];
    int st=1;
    for(int i=1,j=1;;){
        if((i==1 && j%2==0)||(i==n && j%2==1))j++;
        else{
            if(j%2==1)i++;
            else i--;
        }
        st++;
        if(cspj[st]==rs){
            cout << j << " " << i;
            break;
        }
    }
    return 0;
}
