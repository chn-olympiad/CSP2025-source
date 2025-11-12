#include<bits/stdc++.h>
using namespace std;
string s;
int q[9];
int main(){
	freopen("number.in","in",stdin);
	freopen("number.out","out",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]=='0')q[0]++;
    	else if(s[i]=='1')q[1]++;
    	else if(s[i]=='2')q[2]++;
    	else if(s[i]=='3')q[3]++;
    	else if(s[i]=='4')q[4]++;
    	else if(s[i]=='5')q[5]++;
    	else if(s[i]=='6')q[6]++;
    	else if(s[i]=='7')q[7]++;
    	else if(s[i]=='8')q[8]++;
    	else if(s[i]=='9')q[9]++;
	}
    while(q[9]>0){
    	cout<<9;
    	q[9]--;
	}
    while(q[8]>0){
    	cout<<8;
    	q[8]--;
	}
    while(q[7]>0){
    	cout<<7;
    	q[7]--;
	}
    while(q[6]>0){
    	cout<<6;
    	q[6]--;
	}
    while(q[5]>0){
    	cout<<5;
    	q[5]--;
	}
    while(q[4]>0){
    	cout<<4;
    	q[4]--;
	}
    while(q[3]>0){
    	cout<<3;
    	q[3]--;
	}
    while(q[2]>0){
    	cout<<2;
    	q[2]--;
	}
    while(q[1]>0){
    	cout<<1;
    	q[1]--;
	}
    while(q[0]>0){
    	cout<<0;
    	q[0]--;
	}
    return 0;
}
