#include<bits/stdc++.h>
using namespace std;
string s;
int k=0;
int a[100005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int y=s.size();
    for(int i=0;i<y;i++){
		if(int(s[i])-48>=0&&int(s[i])-48<=9){
		    a[++k]=int(s[i])-48;
		}
	}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
}
