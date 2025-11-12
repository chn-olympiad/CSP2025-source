#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
//bool cmp(string a,string b){
//return a<b;
//}
string s1,s2,s3,s4,s5,s6,s7,s8,s9,s0;
int now1,now2,now3,now4,now5,now6,now7,now8,now9,now0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(0);
	//std::cin.tie(0);
	//std::cout.tie(0);
	string s;
	cin>>s;
	int now=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[now]=s[i];
			now++;
		}
	}
	for(int i=0;i<now;i++){
		if(a[i]=='9'){
		s9[now9]=a[i];
			now9++;
		}
		if(a[i]=='8'){
		s8[now8]=a[i];
			now8++;
		}
		if(a[i]=='7'){
		s7[now7]=a[i];
			now7++;
		}
		if(a[i]=='6'){
		s6[now6]=a[i];
			now6++;
		}
		if(a[i]=='5'){
		s5[now5]=a[i];
			now5++;
		}
		if(a[i]=='4'){
		s4[now4]=a[i];
-			now4++;
		}
		if(a[i]=='3'){
		s3[now3]=a[i];
			now3++;
		}
		if(a[i]=='2'){
		s2[now2]=a[i];
			now2++;
		}
		if(a[i]=='1'){
		s1[now1]=a[i];
			now1++;
		}
		if(a[i]=='0'){
		s0[now0]=a[i];
			now0++;
		}
	}
	for(int i=0;i<now9;i++)cout<<9;
	for(int i=0;i<now8;i++)cout<<8;
	for(int i=0;i<now7;i++)cout<<7;
	for(int i=0;i<now6;i++)cout<<6;
	for(int i=0;i<now5;i++)cout<<5;
	for(int i=0;i<now4;i++)cout<<4;
	for(int i=0;i<now3;i++)cout<<3;
	for(int i=0;i<now2;i++)cout<<2;
	for(int i=0;i<now1;i++)cout<<1;
	for(int i=0;i<now0;i++)cout<<0;
	
	
	return 0;
}//insert([]);
