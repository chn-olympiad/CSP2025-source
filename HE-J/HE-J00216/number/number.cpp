#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    int lx=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
        	lx++;
            a[lx]=s[i]-'0';
        }
    }
    sort(a,a+lx+1);
    for(int i=lx;i>=1;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

