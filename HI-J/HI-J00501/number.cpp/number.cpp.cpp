#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	long long j=1,len=s1.size();
	for(int i=0;i<len;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[j]=int(s1[i])-48;
			j++;
		} 
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j-1;i++) cout<<a[i];
	return 0;
}
