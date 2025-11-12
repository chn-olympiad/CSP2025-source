#include<bits/stdc++.h>
using namespace std;
string s;
int a[100];
int main(){
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	if(s.size()==1){
		cout<<s;
		return 0;
	}else{
		for(int i=0;i<s.size();i++){
		//	cout<<s[i]<<endl;
			if(s[i]=='0'){
				a[0]++;
			}
			if(s[i]=='1'){
				a[1]++;
			}
			if(s[i]=='2'){
				a[2]++;
			}
			if(s[i]=='3'){
				a[3]++;
			}
			if(s[i]=='4'){
				a[4]++;
			}
			if(s[i]=='5'){
				a[5]++;
			}
			if(s[i]=='6'){
				a[6]++;
			}
			if(s[i]=='7'){
				a[7]++;
			}
			if(s[i]=='8'){
				a[8]++;
			}
			if(s[i]=='9'){
				a[9]++;
			}
	
		}
		for(int j=9;j>=0;j--){
			
			if(a[j]!=0){
				for(int i=1;i<=a[j];i++){
					cout<<j;
				}	
			}	
		}
		
	}
	return 0;
}


		
