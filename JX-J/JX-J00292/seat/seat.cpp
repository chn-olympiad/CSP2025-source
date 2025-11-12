#include<bits/stdc++.h>
using namespace std;

int data[15][15];
int a[105];
int b[105];//score high->low
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r_score=a[1];//r score

    sort(a+1,a+1+n*m);

    for(int i=n*m,j=1;i>0;i--,j++){
        b[i]=a[j];
    }
    int b_index=0;

    //==============================
    int hang=1;
    int lie=1;
    while(true){
        for(hang=1;hang<=n;hang++){
            b_index++;
            if(b[b_index]==r_score){
                cout<<lie<<' '<<hang;
                return 0;
            }

        }
        lie++;

        for(hang=n;hang>=1;hang--){
            b_index++;
            if(b[b_index]==r_score){
                cout<<lie<<' '<<hang;
                return 0;
            }

        }
        lie++;
    }
    return 0;
}
