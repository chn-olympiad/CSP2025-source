#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],sum,num,an;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
//		if(s[i]=='0')num++;
	 if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++;	
			}
			
		}
	
	for(int i=0;i<sum;i++){
		for(int j=i+1;j<sum;j++){
			if(a[i]<a[j]){
				an=a[i];
				a[i]=a[j];
				a[j]=an;
				an=0;
			}
			
		}
	}
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
//	for(int i=0;i<num;i++){
//		cout<<0;
//	}
	return 0;
}

