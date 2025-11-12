#include<bits/stdc++.h>
using namespace std;
string s;
int a[115],b[100110],sum,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	if(l==1){
		sum=s[0]-'0';
		cout<<sum;
		return 0;
	}
	for(int i=0;i<l;i++){
		if(s[i]<='Z'&&s[i]>='A'){
			continue;
		}else if(s[i]<='z'&&s[i]>='a'){
			continue;
		}
		a[s[i]-'0'+10]+=1;
		b[s[i]-'0'+10]=s[i]-'0'+10;
		k++;
	}
	sort(b,b+19);
	for(int i=19;i>=10;i--){
		for(int k=0;k<a[b[i]];k++){
			cout<<b[i]-10;
		}
	}
	
	return 0;
}
