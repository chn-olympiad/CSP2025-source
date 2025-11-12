#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	char maxx='0';
	int b=0,id=0;
	int si=s.size();
	for(int j=1;;j++){
		maxx='0';
		b=0;
		for(int i=0;i<si;i++){
			if(s[i]>='0'&&s[i]<='9'){
				if(s[i]>=maxx){
					maxx=s[i];
					id=i;
					b=1;
				}
			}
		}
		s[id]='a';
		if(b==1){
			a+=maxx;
		}
		else if(b==0){
			break;
		}


	}
	cout<<a;
	return 0;
}
