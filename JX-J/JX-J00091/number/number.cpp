#include<bits/stdc++.h>
using namespace std;
string a;
long long n;
long long bj[101]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    n=a.size();
    for(long long i=0;i<n;i++){
        if(a[i]>='0' and a[i]<='9'){
            if(a[i]=='0'){
                bj[0]++;
            }
            else if(a[i]=='1'){
                bj[1]++;
            }
            else if(a[i]=='2'){
                bj[2]++;
            }
            else if(a[i]=='3'){
                bj[3]++;
            }
            else if(a[i]=='4'){
                bj[4]++;
            }
            else if(a[i]=='5'){
                bj[5]++;
            }
            else if(a[i]=='6'){
                bj[6]++;
            }
            else if(a[i]=='7'){
                bj[7]++;
            }
            else if(a[i]=='8'){
                bj[8]++;
            }
            else if(a[i]=='9'){
                bj[9]++;
            }
        }
    }
    for(long long i=9;i>=0;i--){
        for(long long j=1;j<=bj[i];j++){
            cout<<i;
        }

    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
