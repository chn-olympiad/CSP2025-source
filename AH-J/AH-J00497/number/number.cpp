#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],l,sl;
int main(){
	cin.tie(0);
	cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sl=s.size();
    for(int i=0;i<sl;i++){
        if(s[i]>='0'&&s[i]<='9'){
            l++;
            a[l]=s[i]-'0';
        }
    }
    sort(a+1,a+1+l);
    for(int i=l;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
