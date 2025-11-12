
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;cin>>n>>m;
    vector<int> v;
    for (int i=0;i<n*m;i++){
        int num;cin>>num;
        v.push_back(num);
    }
    int mark=v[0];
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    for (int i=0;i<n*m;i++){
        if (v[i]==mark) {
            mark=i+1;
     //       cout<<mark<<endl;
            break;
        }
    }

    int row=mark/n+1-(mark%n==0);
    int col=(row%2==1)?mark-(row-1)*n:n-(mark-(row-1)*n)+1;
    cout<<row<<" "<<col;

    return 0;
}
