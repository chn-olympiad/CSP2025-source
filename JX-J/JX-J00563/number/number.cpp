#include<bits/stdc++.h>
using namespace std;
string s;
char b[1000001]={'0'};
int j=1,num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    num=s.size();
	for(int i=0;i<num;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[j]=s[i];
			j++;
		}
	}
	sort(b+1,b+num+1);
	for(int i=num;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
