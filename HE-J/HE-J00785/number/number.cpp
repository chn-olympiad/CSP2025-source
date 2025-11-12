#include<bits/stdc++.h>
using namespace std;
string s;
long long sum=0,ans=0,num[1000001]={0};
bool cmp(int x,int y){
	if(x>y){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(int i=0;i<=len;i++){
		if(s[i]>=48&&s[i]<=57){
			num[sum]=s[i]-'0';
			sum++;
		}
		
	}
	sort(num+0,num+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<num[i];
	}
	return 0;
} 
