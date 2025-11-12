#include<bits/stdc++.h>
using namespace std;
string s;
long long num_1,num_2,num_3,num_4,num_5,num_6,num_7,num_8,num_9,num_0;
void sigma(){
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1'){
			num_1++;
		}else if(s[i]=='2'){
			num_2++;
		}else if(s[i]=='3'){
			num_3++;
		}else if(s[i]=='4'){
			num_4++;
		}else if(s[i]=='5'){
			num_5++;
		}else if(s[i]=='6'){
			num_6++;
		}else if(s[i]=='7'){
			num_7++;
		}else if(s[i]=='8'){
			num_8++;
		}else if(s[i]=='9'){
			num_9++;
		}else if(s[i]=='0'){
			num_0++;
		}
	}
}
void output_(){
	for(int i=0;i<num_9;i++){
		cout<<9;
	}
	for(int i=0;i<num_8;i++){
		cout<<8;
	}
	for(int i=0;i<num_7;i++){
		cout<<7;
	}
	for(int i=0;i<num_6;i++){
		cout<<6;
	}
	for(int i=0;i<num_5;i++){
		cout<<5;
	}
	for(int i=0;i<num_4;i++){
		cout<<4;
	}
	for(int i=0;i<num_3;i++){
		cout<<3;
	}
	for(int i=0;i<num_2;i++){
		cout<<2;
	}
	for(int i=0;i<num_1;i++){
		cout<<1;
	}
	for(int i=0;i<num_0;i++){
		cout<<0;
	}
}
bool allzro(){
	return num_0==0&&num_1==0&&num_2==0&&num_3==0&&num_4==0&&num_5==0&&num_6==0&&num_7==0&&num_8==0&&num_9==0;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    sigma();
	if(allzro()){
		cout<<0<<endl;
		return 0;
	}else{
		output_();
		cout<<endl;
	}
    return 0;
}
