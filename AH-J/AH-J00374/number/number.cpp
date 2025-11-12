#include<bits/stdc++.h>
using namespace std;
int k=1,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]=='1'){
			a[k]=1;
			k++;
			}			
		if(s[i]=='2'){
			a[k]=2;
			k++;
			}
		if(s[i]=='3'){
			a[k]=3;
			k++;
			}
		if(s[i]=='4'){
			a[k]=4;
			k++;
			}
		if(s[i]=='5'){
			a[k]=5;
			k++;
			}
		if(s[i]=='6'){
			a[k]=6;
			k++;
			}
		if(s[i]=='7'){
			a[k]=7;
			k++;
			}
		if(s[i]=='8'){
			a[k]=8;
			k++;
			}
		if(s[i]=='9'){
			a[k]=9;
			k++;
			}
		if(s[i]=='0'){
			a[k]=0;
			k++;
			}
		
		}
	sort(a+1,a+k+1);
	for(int i=k;i>=2;i--){
		cout<<a[i];
		}
	
	
	
	fclose(stdin);
	fclose(stdout);
}
