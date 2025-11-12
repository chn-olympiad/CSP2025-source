#include<bits/stdc++.h>
using namespace std;
string s;
int maxs[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
		if(s[i]=='0') maxs[0]++;
		else if(s[i]=='1') maxs[1]++;
		else if(s[i]=='2') maxs[2]++;
		else if(s[i]=='3') maxs[3]++;
		else if(s[i]=='4') maxs[4]++;
		else if(s[i]=='5') maxs[5]++;
		else if(s[i]=='6') maxs[6]++;
		else if(s[i]=='7') maxs[7]++;
		else if(s[i]=='8') maxs[8]++;
		else if(s[i]=='9') maxs[9]++;
	}
	if(maxs[9]!=0){
		for(int i=0;i<maxs[9];i++)
		    cout<<"9";
	}
	if(maxs[8]!=0){
		for(int i=0;i<maxs[8];i++)
		    cout<<"8";
	}
	if(maxs[7]!=0){
		for(int i=0;i<maxs[7];i++)
		    cout<<"7";
	}
	if(maxs[6]!=0){
		for(int i=0;i<maxs[6];i++)
		    cout<<"6";
	}
	if(maxs[5]!=0){
		for(int i=0;i<maxs[5];i++)
		    cout<<"5";
	}
	if(maxs[4]!=0){
		for(int i=0;i<maxs[4];i++)
		    cout<<"4";
	}
	if(maxs[3]!=0){
		for(int i=0;i<maxs[3];i++)
		    cout<<"3";
	}
	if(maxs[2]!=0){
		for(int i=0;i<maxs[2];i++)
		    cout<<"2";
	}
	if(maxs[1]!=0){
		for(int i=0;i<maxs[1];i++)
		    cout<<"1";
	}
	if(maxs[0]!=0){
		for(int i=0;i<maxs[0];i++)
		    cout<<"0";
	}
    return 0;
}
