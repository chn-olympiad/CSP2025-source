#include<bits/stdc++.h>
using namespace std;
string a;
string b[1000005];
long long zz=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    for(long long i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            zz++;
            b[zz]=a[i];
        }
    }
    sort(b+1,b+zz+1);
    for(long long i=zz;i>0;i--){
        cout<<b[i];
    }
	return 0;
}
