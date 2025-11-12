#include<iostream> 
using namespace std;
int num[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
		    int t=s[i]-'0';
			num[t]+=1;
		}
	}
	for(int i=15;i>=0;i--){
		while(num[i]!=0){
			num[i]--;
			cout<<i;
		}
	}
	return 0;
}
