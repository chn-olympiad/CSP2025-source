#include<iostream>
#include<string>
#include<cstring> 
#include<algorithm>
#include<iomanip>
using namespace std;
const int N=1000005;
long long num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9' && s[i]>='0'){
			num[j]=(s[i]-=48);
			j++;
		}
	}
	sort(num,num+j);
	for(int i=j-1;i>=0;i--){
		cout<<num[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
