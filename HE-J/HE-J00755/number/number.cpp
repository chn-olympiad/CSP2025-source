#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
string git;
int res;
int bin[12];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>git;
    res=git.length();

    for(int i=res-1;i>=0;i--){
    	if(isdigit(git[i])){
            bin[git[i]-'0']++;
        }
	}
    int g=10;
    while(g--){
        while(bin[g]--){
            cout<<g;
        }
    }


    return 0;
}
