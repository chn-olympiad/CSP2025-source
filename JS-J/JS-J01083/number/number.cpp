#include<bits/stdc++.h>
using namespace std;
long long a[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
	for(long long i=0;i<int(s.size());i++){
		if(s[i]>=48){
		    if(s[i]<58){
                a[s[i]-'0']+=1;
		    }
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			cout<<i;
        }
	}
    return 0;
}
