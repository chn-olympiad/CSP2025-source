#include<bits/stdc++.h>
using namespace std;
const int A=1e6+10;
int a[A],b[A];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    string s,t;
    int k=t.length();
    int x,n;
    cin>>t;
        for(int i=0;i<k;i++){
            s[i]=t[i]-'0';
                if(s[i]==1||s[i]==2||s[i==3]){
                 a[i]=(int)s[i];
                 x=max(a[i],x);
                 b[i]=x;
                 x=a[i+1];
            }
        }
        for(int i=0;i<k;i++){
           cout<<b[i];
        }
	return 0;
}