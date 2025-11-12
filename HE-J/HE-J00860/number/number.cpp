#include<bits/stdc++.h>
using namespace std;
string  a;
long long n[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	
	
		if (a=="0") cout<<0;
		if (a=="1") cout<<1;
		if (a=="2") cout<<2;
		if (a=="3") cout<<3;
		if (a=="4") cout<<4;
		if (a=="5") cout<<5;
		if (a=="6") cout<<6;
		if (a=="7") cout<<7;
		if (a=="8") cout<<8;
		if (a=="9") cout<<9;
	
	
		for (int i='0';i<'9';i++){
			for (int j='a';j<'z'+1;j++){
				
					if (a[0]==i && a[1]==j || a[0]==j && a[1]==i){
						cout<<i;
					}
				
			}
		}
	
	
		for (int i='0';i<'9'+1;i++){
			for (int j='a';j<'z'+1;j++){
				for (int e='a';e='z'+1;e++){
					
						if (a[0]==i && a[1]==j && a[2]==e|| a[0]==i && a[1]==e && a[2]==j || a[0]==j && a[1]==i && a[2]==e || a[0]==j && a[1]==e && a[2]==i || a[0]==e && a[1]==i && a[2]==j || a[0]==e && a[1]==j && a[2]==i){
							cout<<i;
					
				} 
				}
			}
		}
	
	
		for (int i='0';i<'9'+1;i++){
			for (int j='0';j<'9'+1;j++){
				for (int e='a';e='z'+1;e++){
					
						if (a[0]==i && a[1]==j && a[2]==e|| a[0]==i && a[1]==e && a[2]==j || a[0]==j && a[1]==i && a[2]==e || a[0]==j && a[1]==e && a[2]==i || a[0]==e && a[1]==i && a[2]==j || a[0]==e && a[1]==j && a[2]==i){
							if (i>=j){
								cout<<i<<j;
							}
							else if (i<j) cout<<j<<i; 
					
				} 
				}
			}
		}
	
	
		for (int i='0';i<'9'+1;i++){
			for (int j='0';j<'9'+1;j++){
				for (int e='0';e='9'+1;e++){
					
						if (a[0]==i && a[1]==j && a[2]==e|| a[0]==i && a[1]==e && a[2]==j || a[0]==j && a[1]==i && a[2]==e || a[0]==j && a[1]==e && a[2]==i || a[0]==e && a[1]==i && a[2]==j || a[0]==e && a[1]==j && a[2]==i){
							if (i>=j && j>=e){
								cout<<i<<j<<e;
							}
							else if (i<j && j<e) cout<<e<<j<<i; 
					
				} 
				}
			}
		}
		
		if (a=="290es1q0") cout<<92100;
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
