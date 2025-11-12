#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10];
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	int count=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[0]++;
			count++;
		}
		else if(s[i]=='1'){
			a[1]++;
			count++;
		}
		else if(s[i]=='2'){
			a[2]++;
			count++;
		}
		else if(s[i]=='3'){
			a[3]++;
			count++;
		}
		else if(s[i]=='4'){
			a[4]++;
			count++;
		}
		else if(s[i]=='5'){
			a[5]++;
			count++;
		}
		else if(s[i]=='6'){
			a[6]++;
			count++;
		}
		else if(s[i]=='7'){
			a[7]++;
			count++;
		}
		else if(s[i]=='8'){
			a[8]++;
			count++;
		}
		else if(s[i]=='9'){
			a[9]++;
			count++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
