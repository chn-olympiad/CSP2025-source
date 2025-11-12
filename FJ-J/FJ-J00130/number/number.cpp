#include<bits/stdc++.h>
using namespace std;
string sbb="";
string aa="";
int aaa[1000005];
long long lll,ans;
bool xxxx(char aaa){
	if(aaa=='0'||aaa=='1'||aaa=='2'||aaa=='3'||aaa=='4'||aaa=='5'|aaa=='6'||aaa=='7'||aaa=='8'||aaa=='9'){
		return 1;
	}else{
		return 0;
	}
}
bool cc(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sbb;
	lll=sbb.size();
	if(lll==1){
		cout<<sbb;
	}else if(lll==2){
		if(xxxx(sbb[0])&&xxxx(sbb[1])){
			cout<<sbb;
		}else if(xxxx(sbb[0])&&!(xxxx(sbb[1]))){
			cout<<sbb[0];
		}else if(xxxx(sbb[1])&&!(xxxx(sbb[0]))){
			cout<<sbb[1];
		}
	}
	else{
		for(long long ii=0;ii<lll;ii++){
			if(xxxx(sbb[ii])){
				aa+=sbb[ii];
				ans++;
			}
		}
		for(long long jj=0;jj<=ans;jj++){
			aaa[jj]=aa[jj]-'0';
		}
		sort(aaa+0,aaa+ans+0,cc);
		for(long long kk=0;kk<ans;kk++){
			cout<<aaa[kk];
		}
	}
	return 0;
}
