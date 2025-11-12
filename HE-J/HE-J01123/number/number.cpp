#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a;
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    while(cin>>a)
    	if(a>='0'&&a<='9')
    		t[a-'0']++;
    for(int i=9;i>=0;i--){
    	while(t[i]){
    		cout<<i;
    		t[i]--;
		}
	}
	return 0;
}
// q.7
//~l2
//ÉÏÉÆÈôË® 
//4 3 6 4 
