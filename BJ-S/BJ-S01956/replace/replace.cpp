#include<bits/stdc++.h>
using namespace std;
int having[10000],h=0;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    char rep[2005][2][1000], qu[2005][2][1000], pl[1000];
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>rep[i][0]>>rep[i][1];
    }
    for(int i=0; i<q; i++){
        int ans=0;
        cin>>qu[i][0]>>qu[i][1];
        for(int j=0; j<n; j++){

            int l=strlen(rep[j][0]);
            for(int ii=0; ii<=strlen(qu[i][0])-l; ii++){
                for(int jj=ii; jj<ii+l; jj++){
       //             cout<<j<<" "<<ii<<" "<<jj<<" "<<qu[i][0][jj]<<" "<<rep[j][0][jj-ii]<<endl;
                    //if(ii+l>strlen(qu[i][0])){break;}
                    if(qu[i][0][jj]!=rep[j][0][jj-ii]){break;}

                    if(jj==ii+l-1){having[h]==ii;h++;}
                }
            }
            for(int k=1; k<=h; k++){
                for (int mn=0; mn<strlen(qu[i][0]); mn++){
                    pl[mn]=qu[i][0][mn];
                }
//cout<<"hv"<<having[k]<<endl;
                for(int ii=having[k]; ii<having[k]+strlen(rep[j][1]); ii++){
                    pl[ii]=rep[j][1][ii-having[k]];
    //                cout<<"pl"<<pl<<endl;
                }
                if(1-strcmp(pl,qu[i][1])){
                    ans++;
                }
            }
            h=0;

        }
        cout<<ans<<endl;
        ans=0;
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
