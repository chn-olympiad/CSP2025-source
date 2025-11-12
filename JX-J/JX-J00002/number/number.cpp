#include<bits/stdc++.h>
using namespace std;
string s,num;
int s1,n=1;

//0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx

int main(){
   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    s1=s.size();
    for(int i=0;i<=s1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[n]=s[i];

            n++;
        }

    }
    for(int i=57;i>=48;i--){
        for(int j=1;j<=n;j++){
        if(num[j]==i)cout<<num[j];
        }
    }
    //for(int j=n;j>=1;j--){
      //      int i=j;
        //while(num[i-1]>num[i])
    //}
return 0;
}
