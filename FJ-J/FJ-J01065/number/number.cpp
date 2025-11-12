#include<bits/stdc++.h>
using namespace std;
	string s[100005];
	long long a[100005],ans[100005],b[100005],sum;
	bool f=0;
int main(){
	freopen(" number.in","r",stdin);
	freopen(" number.out","w",stdout);
	while(1){
		int i=0;
		cin>>s[i];
		sum++;
		
		i++;
	}
	for(int i=1;i<=sum;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]+'0';
			b[i]+=1;
		}
	}
	for(int i=1;i<=sum;i++){
		if(b[i]<b[i+1]){
			int a=b[i];
			int c=b[i+1];
			b[i]=c;
			b[i+1]=a;
		}
	}
	for(int i=1;i<=sum;i++){
		cout<<b[i];
	}
}
