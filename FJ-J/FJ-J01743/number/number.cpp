#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int u=a.size();
	int s[10];
	for(int r=0;r<10;r++){
		s[r]=0;
	}
	for(int q=0;q<u;q++){
		if(a[q]=='0'){
			s[0]++;
		}
		if(a[q]=='1'){
			s[1]++;
		}
		if(a[q]=='2'){
			s[2]++;
		}
		if(a[q]=='3'){
			s[3]++;
		}
		if(a[q]=='4'){
			s[4]++;
		}
		if(a[q]=='5'){
			s[5]++;
		}
		if(a[q]=='6'){
			s[6]++;
		}
		if(a[q]=='7'){
			s[7]++;
		}
		if(a[q]=='8'){
			s[8]++;
		}
		if(a[q]=='9'){
			s[9]++;
		}
	}
	for(int w=9;w>=0;w--){
		for(int e=0;e<s[w];e++){
			cout<<w;
		}
	} 
	return 0;
}
