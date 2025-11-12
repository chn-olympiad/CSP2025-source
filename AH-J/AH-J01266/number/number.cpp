#include<bits/stdc++.h>
using namespace std;
string n;
int a1,a2,a3,a4,a5,a6,a7,a8,a9,a0,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int len=n.size();
	for(int i=0;i<len;i++){
		if(n[i]=='0'){
			a0++;
			ans++;
		}else if(n[i]=='1'){
			a1++;
			ans++;
		}else if(n[i]=='2'){
			a2++;
			ans++;
		}else if(n[i]=='3'){
			a3++;
			ans++;
		}else if(n[i]=='4'){
			a4++;
			ans++;
		}else if(n[i]=='5'){
			a5++;
			ans++;
		}else if(n[i]=='6'){
			a6++;
			ans++;
		}else if(n[i]=='7'){
			a7++;
			ans++;
		}else if(n[i]=='8'){
			a8++;
			ans++;
		}else if(n[i]=='9'){
			a9++;
			ans++;
		}
	}
	while(ans--){
		if(a9!=0){
			cout<<9;
			a9--;
		}else if(a8!=0){
			cout<<8;
			a8--;
		}else if(a7!=0){
			cout<<7;
			a7--;
		}else if(a6!=0){
			cout<<6;
			a6--;
		}else if(a5!=0){
			cout<<5;
			a5--;
		}else if(a4!=0){
			cout<<4;
			a4--;
		}else if(a3!=0){
			cout<<3;
			a3--;
		}else if(a2!=0){
			cout<<2;
			a2--;
		}else if(a1!=0){
			cout<<1;
			a1--;
		}else if(a0!=0){
			cout<<0;
			a0--;
		}
	}
	return 0;
}
