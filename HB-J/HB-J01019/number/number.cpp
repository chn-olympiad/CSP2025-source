#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
string s;
int a[N];
int cnt=0,ans=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    while(cnt<s.length()){
        if(s[cnt]<='9'&&s[cnt]>='0'){
            a[ans]=s[cnt]-'0';
            ans++;
        }
        cnt++;
    }
    sort(a,a+ans,cmp);
    for(int i=0;i<ans;i++){
        cout<<a[i];
    }
    return 0;
}
