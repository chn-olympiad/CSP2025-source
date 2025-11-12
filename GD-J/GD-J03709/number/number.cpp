#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(num[i]==0&&i==1){
			cout<<0<<endl;
			break;
		}else{
			cout<<num[i];
		}	 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

