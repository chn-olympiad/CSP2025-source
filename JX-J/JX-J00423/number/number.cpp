#include<bits/stdc++.h>
using namespace std;
string lmj;
int l,ans,yzy[1000001],sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>lmj;
    l=lmj.size();
    for(int i=0;i<l;i++){
        if(lmj[i]>='0'&&lmj[i]<='9'){
            sum++;
            if(lmj[i]=='0'){
                yzy[sum]=0;
            }
            else if(lmj[i]=='1'){
                yzy[sum]=1;
            }
            else if(lmj[i]=='2'){
                yzy[sum]=2;
            }
            else if(lmj[i]=='3'){
                yzy[sum]=3;
            }
            else if(lmj[i]=='4'){
                yzy[sum]=4;
            }
            else if(lmj[i]=='5'){
                yzy[sum]=5;
            }
            else if(lmj[i]=='6'){
                yzy[sum]=6;
            }
            else if(lmj[i]=='7'){
                yzy[sum]=7;
            }
            else if(lmj[i]=='8'){
                yzy[sum]=8;
            }
            else if(lmj[i]=='9'){
                yzy[sum]=9;
            }
        }
    }
    sort(yzy+1,yzy+1+sum);
    for(int i=sum;i>=1;i--){
        cout<<yzy[i];
    }
    return 0;
}
