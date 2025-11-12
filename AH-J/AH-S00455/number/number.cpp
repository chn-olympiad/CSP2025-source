#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
char a;
int cnt[10];
string s;
bool ok=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
    for(int i=9;i>=1;i--){
        for(int j=1;j<=cnt[i];j++){
            cout<<i;
            ok=1;
        }
    }
    if(ok==0){
        cout<<0;
    }else{
        for(int j=1;j<=cnt[0];j++){
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
