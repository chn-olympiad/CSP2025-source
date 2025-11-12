#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof a);
    string s;
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
    }
    int f=0;
    for(int i=9;i>=0;i--){
		if(i==0 && f==0){
			cout<<0;
		}
		else if(a[i]>0){
			if(i>0)f=1;
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
    return 0;
}
