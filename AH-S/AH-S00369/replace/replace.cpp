#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q,a[N][2],l1,l2,cnt;
string s[N][2],t1,t2;
int f(string c){
    for(int i=0;i<c.size();i++)
        if(c[i]=='b') return i;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        a[i][0]=f(s[i][0]);
        a[i][1]=f(s[i][1]);
    }
    while(q--){
        cnt=0;
        cin>>t1>>t2;
        l1=f(t1);
        l2=f(t2);
        for(int i=1;i<=n;i++)
            if(l1-l2==a[i][1]-a[i][0]&&s[i][0].size()-a[i][0]<=t1.size()-l1&&l1>=a[i][0])
                cnt++;
        cout<<cnt<<endl;
    }
	return 0;
}
