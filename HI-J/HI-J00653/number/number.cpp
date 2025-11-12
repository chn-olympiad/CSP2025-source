#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int cs[1000005];
int pc=0,fw=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++){
    	if(s[i]=='0'){
    		pc++;
    		cs[pc]=0;
		}
		if(s[i]=='1'){
    		pc++;
    		cs[pc]=1;
		}
		if(s[i]=='2'){
    		pc++;
    		cs[pc]=2;
		}
		if(s[i]=='3'){
    		pc++;
    		cs[pc]=3;
		}
		if(s[i]=='4'){
    		pc++;
    		cs[pc]=4;
		}
		if(s[i]=='5'){
    		pc++;
    		cs[pc]=5;
		}
		if(s[i]=='6'){
    		pc++;
    		cs[pc]=6;
		}
		if(s[i]=='7'){
    		pc++;
    		cs[pc]=7;
		}
		if(s[i]=='8'){
    		pc++;
    		cs[pc]=8;
		}
		if(s[i]=='9'){
    		pc++;
    		cs[pc]=9;
		}
	}
	sort(cs+pc,cs+pc+1);
	for(int i=1;i<=pc;i++){
		if(cs[i]<cs[i+1]){
			swap(cs[i],cs[i+1]);
		}
	}
	for(int i=1;i<=pc;i++){
		if(cs[i]==0){
			fw++;
		}
	}
	if(fw==pc){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=pc;i++){
		printf("%d",cs[i]);
	}
	return 0;
}

