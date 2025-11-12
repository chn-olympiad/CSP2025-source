#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int a[N];
string s;
bool cmp(int x, int y){
    return x>y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    cin>>s;
    int cnt=0;
    int len=s.size();
    for(int i=0; i<len; i++){
        if(s[i]<='9'&&s[i]>='0'){
			cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1, a+cnt, cmp);
    for(int i=1; i<=cnt; i++){
        cout<<a[i];
    }
    printf("\n");





    return 0;
}
