#include<bits/stdc++.h>
using namespace std;
string s;
char a[100001];
long long f=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long m=s.size();
    for(int i=0;i<=m;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[f]=s[i];
			f++;
		}
	}
	for(int i=f;i>=0;i--){
		for(int j=0;j<=f;j++){
		    if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
	    }
	}
    return 0;
}
