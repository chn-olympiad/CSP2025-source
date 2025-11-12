#include<bits/stdc++.h>
using namespace std;
int s;
int main(){
    cin>>s;
    while(s){
        s--;
        int n,b[100001][5],ans[100001],d=0;
        cin >>n;
        cin >> d;
        for(int i=1;i<=n;i++)
            for(int j=1  ;j<=3 ;j++){
                    cin >>b[i][j];
                    ans[i]=max(b[i][j],ans[i]);
            }
        sort(ans+1,ans+n+1);
        for(int i =(n+1)/2;i<=n;i++)d+=ans[i];
        cout << d;

    }
    return 0;

}
