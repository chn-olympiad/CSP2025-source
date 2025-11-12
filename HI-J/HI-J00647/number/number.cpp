#include <bits/stdc++.h>
using namespace std;
string s;
int a[10005],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(isdigit(s[i])){
			if(int(s[i])==48){
				a[i]=1;
			}else{
				a[i]=int(s[i])-48;
			}
//			cout<<a[i]<<endl;
			cnt++;	
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
