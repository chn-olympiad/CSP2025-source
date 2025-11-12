#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
string s;
int main(){
				freopen("number.in","r",stdin);
				freopen("number.out","w",stdout);
				cin>>s;
				for(int i=0;i<s.size();i++){
								if(s[i]>='0'&&s[i]<='9'){
												a[s[i]-'0']++;
								}
				}
				int flag1=0,flag2=0;
				if(a[0]) flag1=1;
				for(int i=1;i<=9;i++){
								if(a[i]) flag2=1;
				}
				if(flag1!=0&&flag2==0){
								cout<<0;
								return 0;
				}
				for(int i=9;i>=0;i--){
								for(int j=1;j<=a[i];j++){
												cout<<i;
								}
				}
				return 0;
}
