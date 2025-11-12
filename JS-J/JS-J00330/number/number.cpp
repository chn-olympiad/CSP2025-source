#include <bits/stdc++.h>
using namespace std;
string s;
int s1,a[100],i=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    s1=s+0;
    a[i]=s1%10;
    while(s!=0){
            a[i]=max(a[i],s%10);
            s/10;
            i++;
    }
    for(int j=0;j<=i;j++){
        cout<<a[j];
    }
	return 0;
}
