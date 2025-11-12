#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len;
bool cp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	len=s.size();
	int j=1;
	for(int i=0;i<len;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[j]=s[i]-'0';
			j++;
		}	
	}
	sort(a+1,a+j+1,cp);
	if(a[1]!=0){
		for(int i=1;i<=j-1;i++){
			cout<<a[i];
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
