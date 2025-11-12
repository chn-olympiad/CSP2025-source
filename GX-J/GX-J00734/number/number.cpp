#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],l;
bool tf=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
			if(i!=0){
				tf=true;
			}else if(tf==false){
				break;
			}
		}
	}
	return 0;
}
