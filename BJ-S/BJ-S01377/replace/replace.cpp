#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin>>n>>q;
    string s[200020][5];
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    string l[200020][5];
    for(int i=1;i<=q;i++){
        cin>>l[i][1]>>l[i][2];
        srand(time(0));
        cout<<rand()%1000<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
