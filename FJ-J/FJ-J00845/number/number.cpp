#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s = {};
	cin>>s;
	int a[10001] = { },m = 0,i = 0;
    for(int i = 0;i <= 1000;i++){
    	if('0'<=s[i]<='9'){
    	if(s[i] == '0'){
    		a[m] = 0;
    		m++;
		}else if(s[i]=='1'){
			a[m] = 1;
			m++; 
		}else	if(s[i] == '2'){
    		a[m] = 2;
    		m++;
		}else	if(s[i] == '3'){
    		a[m] = 3;
    		m++;
		}else	if(s[i] == '4'){
    		a[m] = 4;
    		m++;
		}else	if(s[i] == '5'){
    		a[m] = 5;
    		m++;
		}else	if(s[i] == '6'){
    		a[m] = 6;
    		m++;
		}else	if(s[i] == '7'){
    		a[m] = 7;
    		m++;
		}else	if(s[i] == '8'){
    	    a[m] = 8;
    		m++;
		}else	if(s[i] == '9'){
    		a[m] = 9;
    		m++;
		}}
	}
	int p[m/2-1] = {},l,o = m/2-1;
	for(int j = 0;j <= m/2-1;j++){
	int max = 0;		
	for(int i = 0;i <= m/2-1;i++){
		if(a[i]>max){
			max = a[i];
			l = i;
		}
	} 
	p[j] = a[l];
	a[l] = 0;
}
	for(int i = 0;i <= o;i++){
		cout<<p[i];
	}
	return 0;
}
