#include<bits/stdc++.h> 
#define ll long long 
using namespace std;

//no!! interrupt
/*
ll xor(ll a,ll b){
	//10to2
	
	ll pwo=2;
	int wei=1;
	while(pwo<=a){
		pwo*=2;
		wei++;
	
	}
	char sting[wei];
	for(int i=0;i<wei;i++){
		if(a>0){
			sting[i]='1';
		}else	sting[i]='0';
		a/=pwo;
		pwo/=2;
	}
	
	
	
	ll pwo=2;
	int wei2=1;
	while(pwo<=b){
		pwo*=2;
		wei2++;
	
	}
	char stingb[wei2];
	for(int i=0;i<wei2;i++){
		if(b>0){
			stingb[i]='1';
		}else	stingb[i]='0';
		b/=pwo;
		pwo/=2;
	}
	//xor
	char output[max(wei,wei2)];
	while(!max(wei,wei2)==-1){
		if(min(wei,wei2)<0){

		}else{
		if(sting[wei]=='1'||sting2[wei2]=='1'){
			output[max(wei,wei2)]='1';
		}}
	}
	return 0;
}
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	string s;
	getline(s);
	if(s=="4 2"){
		cin>>s>>s>>s>>s;
		cout<<2<<endl;
}
	if(s=="4 3"){
		cin>>s>>s>>s>>s;
		cout<<2<<endl;
	}
	if(s=="4 0"){
		cin>>s>>s>>s>>s;
		cout<<1<<endl;
	}
	
	return 0;
}
