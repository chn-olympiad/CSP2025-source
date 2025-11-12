#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int nums[15];
int main(){
    freopen("number.in","r",stdin);                                          
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=0;i<int(s.size());i++){
        if(s[i]>='0' && s[i]<='9'){
            //cout<<int(s[i]-'0');                                              
            nums[int(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=nums[i];j++){
            cout<<char(char(i)+'0');
		}
	}
	return 0;
}
