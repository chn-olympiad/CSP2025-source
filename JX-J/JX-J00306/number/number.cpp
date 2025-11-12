#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
char n[N],a[N];
long long pos;
string b;
bool f=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
    for(long long i=0;i<strlen(n);i++){
        if(isdigit(n[i])){
                a[pos++]=n[i];
                if(a[i]!='0') f=1;
        }
    }
    if(f){
        sort(a,a+pos,cmp);
        cout<<a;
    }
    else cout<<0;
	return 0;
}
