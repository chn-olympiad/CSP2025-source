#include<bits/stdc++.h>
#define ll long long

using namespace std;
long a[20]={0};

inline void solve(){
	string s;
	getline(cin,s);
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			a[0]++;
		}
		if(s[i]=='1'){
			a[1]++;
		}
		if(s[i]=='2'){
			a[2]++;
		}
		if(s[i]=='3'){
			a[3]++;
		}
		if(s[i]=='4'){
			a[4]++;
		}
		if(s[i]=='5'){
			a[5]++;
		}
		if(s[i]=='6'){
			a[6]++;
		}
		if(s[i]=='7'){
			a[7]++;
		}
		if(s[i]=='8'){
			a[8]++;
		}
		if(s[i]=='9'){
			a[9]++;
		}
	}
	for(int o=9;o>=0;o--){
		for(int i=0;i<a[o];i++){
			if(o==0){
				printf("%c",'0');
			}
			if(o==1){
				printf("%c",'1');
			}
			if(o==2){
				printf("%c",'2');
			}
			if(o==3){
				printf("%c",'3');
			}
			if(o==4){
				printf("%c",'4');
			}
			if(o==5){
				printf("%c",'5');
			}
			if(o==6){
				printf("%c",'6');
			}
			if(o==7){
				printf("%c",'7');
			}
			if(o==8){
				printf("%c",'8');
			}
			if(o==9){
				printf("%c",'9');
			}
		}
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	T=1;
	while(T--){
		solve();
	}
}
